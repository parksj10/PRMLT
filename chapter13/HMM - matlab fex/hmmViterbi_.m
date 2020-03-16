function [S, logP] = hmmViterbi_(O, lambda)
% Implmentation function of Viterbi algorithm. 
% Input:
%   O: 1 x T observation sequence
%   A: k x k transition matrix
%   B: N x M emmision data matrix
%   s: k x 1 starting probability (prior)
% Output:
%   z: 1 x n latent state
%   p: 1 x n probability
% Written by Josh Parks
A = lambda.A;
B = lambda.B;
pi = lambda.pi;
N = size(A,1);
T = numel(O);
logA = log(A);
logB = log(B);
P = log(pi(:))+logB(:,O(1));
psi = zeros(N,T);
delta = zeros(N,T); %actually this is log(delta) --> phi, but leave as delta for clarity
S = zeros(1,T);

% decode all time points
for t = 2:T
    for i = 1:N
        % avoid max with loop
        delta_max = -inf;
        psi_max = 0;
        for j = 1:N
            delta_temp = P(j) + logA(i,j);
            if delta_temp > delta_max
                delta_max = delta_temp;
                psi_max = j;
            end 
        end
        % save best state for backtracking
        delta(i,t) = delta_max;
        psi(i,t) = psi_max;
        % update probability
        P(i) = B(i,O(t)) + delta_max;
    end
end

%decide final state from max P
[logP, s_T] = max(P);
% Now back trace through the model
S(T) = s_T;
for t = T-1:-1:1
    S(t) = psi(S(t+1),t+1);
    if psi(S(t+1),t+1) == 0
        error(message('stats:hmmviterbi:ZeroTransitionProbability', psi(t+1)));
    end
end

