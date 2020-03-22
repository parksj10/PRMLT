function [viterbi, opt, lambda, llh, logP] = hmmF(varargin)
%HMMF - Fluxus implementation of HMM for photon data
% Input:
%   data - vector of binned data
% Input arguments:
% data    row vector of binned data, of size 1xT
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Options is an optional set of Name/Value pairs of control parameters
%         of the algorithm. It may also be preset by calling:
%         Options = hmmF; %   for setting default values for Options,
%         Options = hmmF('default');  or by a set of Name/Value pairs:
%         Options = LMFnlsq('Name',Value, ... ), or updating the Options
%                   set by calling
%         Options = LMFnlsq(Options,'Name',Value, ...).
% Name   Values {default}               Description
% 'N'               {4}                 Number of states (including BG state)
% 'M'               {171}               Number of observation symbols
%                                       maximum possible rate for observation - 1, 
%                                       e.g. max photon per bin - 1
%                                           {v_k} = {0,1,2,...,Omax}
%                                       *** include zero in vk -- max rate is 170
% 'a11'             {0.9999999}         Initial guess at staying background
% 'aii'             {0.8}               Initial guess at staying in a given state
% 'rate1'           {1}                 Initial guess at rate 1, i.e. background
%                                           count rate per bin (mean)
% 'rate2'           {3}                 Initial guess at rate 2, i.e. signal
%                                           count rate per bin (mean)
% 'maxIter'         {10}                Initial guess at staying background
% 'tol'             {1e-9}               Minimum step between EM steps
%                                           before finishing
% 'lambda'          {lambda.A = A;      A = Transition probability matrix -
%                                       NxN
%                   lambda.B = B;       B = Emission probability matrix -
%                                       NxM
%                   lambda.pi = pi;}    pi = initial probability vector
%                                       Nx1 (should technically be 1xN,
%                                       keep convention of original author)
% Written by Josh Parks.

debug = true;

if debug == false
%return help for no args
if nargin==0 && nargout==0, help hmmF, return, end

%   Options = hmmF;
%   Options = hmmF('default');
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%
%       Default Options
if nargin==0 || (nargin==1 && strcmpi('default',varargin(1)))
    opt.N = 4;
    opt.M = 171;
    opt.a11 = 0.9999999;
    opt.aii = 0.8;
    opt.rate1 = 1;
    opt.rate2 = 3;
    opt.maxIter = 10;
    opt.tol = 1e-9;
%     %static definitions of A, E, and s for clarity
%     opt.lambda.A = [a11      1-aii   0       0       ;
%                    0        aii     1-aii   0       ;
%                    0        0       aii     1-aii   ;
%                    1-aii    0       0       aii     ];          
%     opt.lambda.B = [poisspdf(0:1:opt.Omax, opt.rate1);
%                    poisspdf(0:1:opt.Omax, opt.rate2);
%                    poisspdf(0:1:opt.Omax, opt.rate2);
%                    poisspdf(0:1:opt.Omax, opt.rate2)];
%     opt.lambda.pi = [a11;
%                    1-a11/(N-1)
%                    1-a11/(N-1)
%                    1-a11/(N-1)]; %assume column stochastic (sums to 1)

    opt.lambda.A = eye([opt.N opt.N]).*opt.aii + ...
                  circshift(eye([opt.N opt.N]),-1).*(1-opt.aii);
    opt.lambda.A(1,1) = opt.a11;
    opt.lambda.A(1,2) = 1-opt.a11;
    %B matrix should be NxM, so fill with poisson photon statistics for
    %number of states (N) rows, given the average rate, set non BG to rate2
    opt.lambda.B = vertcat(poisspdf(0:1:opt.M-1, opt.rate1),...
                ones(opt.N-1,opt.M).*poisspdf(0:1:(opt.M-1), opt.rate2));
    opt.lambda.pi = vertcat(opt.a11,ones(opt.N-1,1).*(1-opt.a11/(opt.N-1)));
   return

%   Options = hmmF(Options,name,value,...);
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%       Updating Options
elseif isstruct(varargin{1}) % Options=hmmF(Options,'Name','Value',...)
    if ~isfield(varargin{1},'Jacobian')
        error('Options Structure not Correct for hmmF.')
    end
    opt=varargin{1};          %   Options
    for i=2:2:nargin-1
        name=varargin{i};    %   option to be updated
        if ~ischar(name)
            error('Parameter Names Must be Strings.')
        end
        value=varargin{i+1}; %   value of the option
        if     strncmp(name,'N',1), opt.N               = value;
        elseif strncmp(name,'M',1), opt.M               = value;
        elseif strncmp(name,'a11',3), opt.a11           = value;
        elseif strncmp(name,'aii',3), opt.aii           = value;
        elseif strncmp(name,'rate1',5), opt.rate1       = value;
        elseif strncmp(name,'rate2',5), opt.rate2       = value;
        elseif strncmp(name,'maxIter',7), opt.maxIter   = value;
        elseif strncmp(name,'tol',3), opt.tol           = value;
        elseif strncmp(name,'lambda',5), opt.lambda       = value;
        else   disp(['Unknown Parameter Name --> ' name])
        end
    end
    return

%   Options = hmmF(name,value,...);
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%       Pairs of Options
elseif ischar(varargin{1})  % check for Options=hmmF('Name',Value,...)
   Pnames=char('N','M','a11','aii','rate1','rate2','lambda','maxIter','tol');
   if strncmpi(varargin{1},Pnames,length(varargin{1}))
      opt=hmmF('default');  % get default values
      opt=hmmF(opt,varargin{:});
      return
   end
end

%   [Xf,Ssq,CNT,Res,XY] = hmmF(data,Options);
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%               OPTIONS
%               *******
data=varargin{1};            %   input data
if ~(ismatrix(varargin{1}) || size(varargin{1},2) == 1)
    error('First argument needs to be 1xT vector.')
end
if ~exist('options','var')
    options = hmmF('default');
end
if nargin>2                 %   OPTIONS
    if isstruct(varargin{3})
        options=varargin{3};
    else
        for i=3:2:size(varargin,2)-1
            options=hmmF(options, varargin{i},varargin{i+1});
        end
    end
else
    if ~exist('options','var')
        options = hmmF('default');
    end
end

else % debug
    
opt.N = 4;
opt.M = 171;
opt.a11 = 0.9999999;
opt.aii = 0.8;
opt.rate1 = 1;
opt.rate2 = 3;
opt.maxIter = 10;
opt.tol = 1e-9;

opt.lambda.A = eye([opt.N opt.N]).*opt.aii + ...
              circshift(eye([opt.N opt.N]),-1).*(1-opt.aii);
opt.lambda.A(1,1) = opt.a11;
opt.lambda.A(1,2) = 1-opt.a11;
%B matrix should be NxM, so fill with poisson photon statistics for
%number of states (N) rows, given the average rate, set non BG to rate2
opt.lambda.B = vertcat(poisspdf(0:1:opt.M-1, opt.rate1),...
            ones(opt.N-1,opt.M).*poisspdf(0:1:(opt.M-1), opt.rate2));
opt.lambda.pi = vertcat(opt.a11,ones(opt.N-1,1).*(1-opt.a11/(opt.N-1)));
options = opt;
% data = readNPY('002_NP-Crstd@1E7npsml.npy')';

end % debug check
load('input.mat');
%% matlab index change
data = data + 1; 

%% save run options for output
opt = options;
addpath ( genpath ( pwd ) )
% % run baum-welch (EM) optimization
% % [lambdaO, llh] = hmmEm(data,opt.lambda);
% % [lambdaO.A, lambdaO.E] = hmmtrain(data,opt.lambda.A,opt.lambda.B);
[lambda, llh] = hmmEM(data, opt.lambda, opt.maxIter, opt.tol);
% 
% % run viterbi decoding
% % viterbi = hmmViterbi(data,lambdaO);
% % [viterbi, logP] = hmmViterbi(data,lambdaO.A,lambdaO.B,lambdaO.pi);
[viterbi, logP] = hmmViterbi(data,lambda);

% C dll version
% addpath ( genpath ( pwd ) )
% loadlibrary('hmmEM.dll','hmmEM.h')
% [lambda, llh] = calllib('hmmEM','hmmEM',data, opt.lambda, opt.maxIter, opt.tol, llh);

stop;

end %hmmF

