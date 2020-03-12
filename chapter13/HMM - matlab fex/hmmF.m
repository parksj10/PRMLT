function [opt, modelO, llh, viterbi] = hmmF(varargin)
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
% Name   Values {default}           Description
% 'N'               {4}          	Number of states (including BG state)
% 'M'               {171}         	Number of observation symbols
%                                   maximum possible rate for observation - 1, 
%                                   e.g. max photon per bin - 1
%                                       {v_k} = {0,1,2,...,Omax}
%                                   *** include zero in vk -- max rate is 170
% 'bin'             {1e-5}          Bin time, in seconds
% 'a11'             {0.9999999}     Initial guess at staying background
% 'aii'             {0.8}           Initial guess at staying in a given state
% 'lambda1'         {1}          	Initial guess at rate 1, i.e. background
%                                       count rate per bin (mean)
% 'lambda2'         {3}             Initial guess at rate 2, i.e. signal
%                                       count rate per bin (mean)
% 'model'           {model.A = A;   A = A = Transition probability matrix -
%                                       NxN
%                    model.E = E;   E = b = Emission probability matrix -
%                                       NxM
%                    model.s = s;}  s = pi = initial probability vector
%                                       Nx1 (should technically be 1xN,
%                                       keep convention of original author)
% Written by Josh Parks.
% Core algorithm adapted from Mo Chen (sth4nth@gmail.com), 
% Bishop, C. M. Pattern Recognition and Machine Learning. (Springer, 2011)
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
    opt.bin = 1e-5;
    opt.a11 = 0.9999999;
    opt.aii = 0.8;
    opt.lambda1 = 1;
    opt.lambda2 = 3;
%     %static definitions of A, E, and s for clarity
%     opt.model.A = [a11      1-aii   0       0       ;
%                    0        aii     1-aii   0       ;
%                    0        0       aii     1-aii   ;
%                    1-aii    0       0       aii     ];          
%     opt.model.E = [poisspdf(0:1:opt.Omax, opt.lambda1);
%                    poisspdf(0:1:opt.Omax, opt.lambda2);
%                    poisspdf(0:1:opt.Omax, opt.lambda2);
%                    poisspdf(0:1:opt.Omax, opt.lambda2)];
%     opt.model.s = [a11;
%                    1-a11/(N-1)
%                    1-a11/(N-1)
%                    1-a11/(N-1)]; %assume column stochastic (sums to 1)

    opt.model.A = eye([opt.N opt.N]).*opt.aii + ...
                  circshift(eye([opt.N opt.N]),-1).*(1-opt.aii);
    opt.model.A(1,1) = opt.a11;
    %E matrix should be NxM, so fill with poisson photon statistics for
    %number of states (N) rows, given the average rate, set non BG to rate2
    opt.model.E = vertcat(poisspdf(0:1:opt.M-1, opt.lambda1),...
                ones(opt.N-1,opt.M).*poisspdf(0:1:(opt.M-1), opt.lambda2));
    opt.model.s = vertcat(opt.a11,ones(opt.N-1,1).*(1-opt.a11/(opt.N-1)));
   return

%   Options = hmmF(Options,name,value,...);
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%       Updating Options
elseif isstruct(varargin{1}) % Options=hmmF(Options,'Name','Value',...)
    if ~isfield(varargin{1},'Jacobian')
        error('Options Structure not Correct for hmmF.')
    end
    xf=varargin{1};          %   Options
    for i=2:2:nargin-1
        name=varargin{i};    %   option to be updated
        if ~ischar(name)
            error('Parameter Names Must be Strings.')
        end
        value=varargin{i+1}; %   value of the option
        if     strncmp(name,'N',1), opt.N               = value;
        elseif strncmp(name,'M',1), opt.M               = value;
        elseif strncmp(name,'bin',1), opt.bin           = value;
        elseif strncmp(name,'a11',1), opt.a11           = value;
        elseif strncmp(name,'aii',1), opt.aii           = value;
        elseif strncmp(name,'lambda1',1), opt.lambda1   = value;
        elseif strncmp(name,'lambda2',1), opt.lambda2   = value;
        elseif strncmp(name,'model',1), opt.model       = value;
        else   disp(['Unknown Parameter Name --> ' name])
        end
    end
    return

%   Options = hmmF(name,value,...);
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%       Pairs of Options
elseif ischar(varargin{1})  % check for Options=hmmF('Name',Value,...)
   Pnames=char('N','M','bin','a11','aii','lambda1','lambda2','model');
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
opt.bin = 1e-5;
opt.a11 = 0.9999999;
opt.aii = 0.8;
opt.lambda1 = 1;
opt.lambda2 = 3;
%     %static definitions of A, E, and s for clarity
%     opt.model.A = [a11      1-aii   0       0       ;
%                    0        aii     1-aii   0       ;
%                    0        0       aii     1-aii   ;
%                    1-aii    0       0       aii     ];          
%     opt.model.E = [poisspdf(0:1:opt.Omax, opt.lambda1);
%                    poisspdf(0:1:opt.Omax, opt.lambda2);
%                    poisspdf(0:1:opt.Omax, opt.lambda2);
%                    poisspdf(0:1:opt.Omax, opt.lambda2)];
%     opt.model.s = [a11;
%                    1-a11/(N-1)
%                    1-a11/(N-1)
%                    1-a11/(N-1)]; %assume column stochastic (sums to 1)

opt.model.A = eye([opt.N opt.N]).*opt.aii + ...
              circshift(eye([opt.N opt.N]),-1).*(1-opt.aii);
opt.model.A(1,1) = opt.a11;
%E matrix should be NxM, so fill with poisson photon statistics for
%number of states (N) rows, given the average rate, set non BG to rate2
opt.model.E = vertcat(poisspdf(0:1:opt.M-1, opt.lambda1),...
            ones(opt.N-1,opt.M).*poisspdf(0:1:(opt.M-1), opt.lambda2));
opt.model.s = vertcat(opt.a11,ones(opt.N-1,1).*(1-opt.a11/(opt.N-1)));
options = opt;
data = readNPY('002_NP-Crstd@1E7npsml.npy')';

end

%save run options for output
opt = options;

%run baum-welch (EM) optimization
[modelO, llh] = hmmEm(data,opt.model);
[modelO.A, modelO.E] = hmmtrain(data,opt.model.A,opt.model.E);

%run viterbi decoding
viterbi = hmmViterbi(data,modelO);


    
    
end %hmmF

