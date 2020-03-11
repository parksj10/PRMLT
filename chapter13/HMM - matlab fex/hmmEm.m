function [model, llh] = hmmEm(x, init)
% EM algorithm to fit the parameters of HMM model (a.k.a Baum-Welch algorithm)
% Input:
%   x: 1 x n integer vector which is the sequence of observations
%   init: model or k
% Output:s
%   model: trained model structure
%   llh: loglikelihood
% Written by Mo Chen (sth4nth@gmail.com).

% init with a model
A = init.A;
E = init.E;
s = init.s;

d = size(E,2); %M
n = size(x,2); %T
X = sparse(x+1,1:n,1,d,n); %+1 to account for matlab 1 indexing (i.e. row 1 is for 0 cts)
M = E*X;

tol = 1e-4;
maxIter = 10;
llh = -inf(1,maxIter);
for iter = 2:maxIter
%     E-step
    [gamma,alpha,beta,c] = hmmSmoother_(M,A,s);
    llh(iter) = sum(log(c(c>0)));
    if llh(iter)-llh(iter-1) < tol*abs(llh(iter-1)); break; end   % check likelihood for convergence
%     M-step 
    A = normalize(A.*(alpha(:,1:n-1)*bsxfun(@times,beta(:,2:n).*M(:,2:n),1./c(2:end))'),2);      % 13.19
    s = gamma(:,1);                                                                             % 13.18
    M = bsxfun(@times,gamma*X',1./sum(gamma,2))*X;                                          
end
llh = llh(2:iter);
model.A = A;
model.E = E;
model.s = s;


