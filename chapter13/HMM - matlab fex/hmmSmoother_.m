function [gamma, alpha, beta, c] = hmmSmoother_(O, A, B, s)
% Implmentation function HMM smoothing alogrithm.
% Unlike the method described in the book of PRML, the alpha returned is the normalized version: gamma(t)=p(z_t|x_{1:T})
% Computing unnormalized version gamma(t)=p(z_t,x_{1:T}) is numerical unstable, which grows exponential fast to infinity.
% Input:
%   M: k x n emmision data matrix M=E*X
%   A: k x k transition matrix
%   s: k x 1 start prior probability
% Output:
%   gamma: k x n matrix of posterior gamma(t)=p(z_t,x_{1:T})
%   alpha: k x n matrix of posterior alpha(t)=p(z_t|x_{1:T})
%   beta: k x n matrix of posterior beta(t)=gamma(t)/alpha(t)
%   c: loglikelihood
% Written by Mo Chen (sth4nth@gmail.com).
T = numel(O);
[N, M] = size(B);
c = zeros(1,T); % normalization constant
alpha = zeros(N,T);
alpha(:,1) = s(:) + c(1);
%scale alpha1
alpha(:,1) = alpha(:,1)./c(1);

%compute alpha_t(i)
for t = 2:T
    c(t) = 0;
    for j = 1:N
        alpha(j,t) = 0; %initialize alpha_t(j)
        for i = 1:N
            alpha(j,t) = alpha(i,t) + alpha(i,t-1)*A(i,j);
        end %i
        alpha(j,t) = alpha(j,t)*B(j,O(t));
        c(t) = c(t) + alpha(j,t);
    end %j
    alpha(:,t) = alpha(:,t)./c(t); %scale alpha
end




for t = 2:T
    [alpha(:,t),c(t)] = normalize((At*alpha(:,t-1)).*M(:,t),1);  % 13.59
end
beta = ones(K,T);
for t = T-1:-1:1
    beta(:,t) = A*(beta(:,t+1).*M(:,t+1))/c(t+1);   % 13.62
end
gamma = alpha.*beta;                  % 13.64

