function [gamma, epsilon, alpha, beta, c] = hmmSmoother_(O, lambda)
% Implmentation function HMM smoothing alogrithm.
% Unlike the method described in the book of PRML, the alpha returned is the normalized version: gamma(t)=p(z_t|x_{1:T})
% Computing unnormalized version gamma(t)=p(z_t,x_{1:T}) is numerical unstable, which grows exponential fast to infinity.
% Input:
%   O:  1 x T observation matrix
%   A:  N x N transition probability matrix
%   B:  M x N emission probability matrix
%   pi: N x 1 start prior probability
% Output:
%   gamma:   N x T      smoothed node marginals gamma(i,t)=p(O1:Ot, s_i | lambda)
%   epsilon: N x N x T  smoothed edge marginals epsilon(i,j,t)=p(s_i, s_j | O, lambda)
%   alpha: k x n matrix of posterior alpha(t)=p(z_t|x_{1:T})
%   beta: k x n matrix of posterior beta(t)=gamma(t)/alpha(t)
%   c: loglikelihood
% Written by Mo Chen (sth4nth@gmail.com).
T = numel(O);
A = lambda.A;
B = lambda.B;
pi = lambda.pi;
N = size(A,1);
c = zeros(1,T); % normalization constant

%% alpha calc
alpha = zeros(N,T);

%alpha_1
for i = 1:N
    alpha(i,1) = pi(i)*B(1,O(1));
    c(1) = c(1) + alpha(i,1);
end
%scale alpha_1
c(1) = 1/c(1);
for i = 1:N
    alpha(i,1) = c(1)*alpha(i,1);
end

%compute alpha_t(i)
for t = 2:T
    c(t) = 0;
    for j = 1:N
        alpha(j,t) = 0; %initialize alpha_t(j)
        for i = 1:N
            alpha(j,t) = alpha(j,t) + alpha(i,t-1)*A(i,j);
        end %i
        alpha(j,t) = alpha(j,t)*B(j,O(t));
        c(t) = c(t) + alpha(j,t);
    end %j
    %scale alpha_t
    c(t) = 1/c(t);
    for j = 1:N
        alpha(j,t) = c(t)*alpha(j,t);
    end
end %t

%% beta calc
beta = zeros(N,T);

%beta_T scaling
for i = 1:N
    beta(i,T) = c(T)*1; % initialization says beta_T = 1
end

%beta_t(i)
for t = T-1:-1:1
    for i = 1:N
        beta(i,t) = 0;
        for j = 1:N
            beta(i,t) = beta(i,t) + A(i,j)*B(j,O(t+1))*beta(j,t+1);
        end %j
        %scale beta_t with same c_t as alpha_t
        beta(i,t) = c(t)*beta(i,t);
    end %i
end %t

%compute epsilon_t and gamma_t (no need to normalize, alpha and beta are scaled)
epsilon = zeros(N,N,T-1); %also called "di-gamma"
gamma = zeros(N,T);
for t = 1:T-1
    for i = 1:N
        gamma(i,t) = 0;
        for j = 1:N
            if t == 3001344
                hold = 1;
            end
            epsilon(i,j,t) = alpha(i,t)*A(i,j)*B(j,O(t+1))*beta(j,t+1);
            gamma(i,t) = gamma(i,t) + epsilon(i,j,t);
        end %j
    end %i
end %t

%special case gamma
for i = 1:N
    gamma(i,T) = alpha(i,T);
end
