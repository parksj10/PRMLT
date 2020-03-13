function [S, logP] = hmmViterbi_(O, A, B, s)
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
k = size(A,1);
n = numel(O);
logA = log(A);
logB = log(B);
P = log(s(:))+logB(:,O(1));
psi = zeros(k,n);
delta = zeros(k,n);
S = zeros(1,n);
for t = 2:n
    for i = 1:k
        % avoid max with loop
        delta_max = -inf;
        psi_max = 0;
        for j = 1:k
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
S(n) = s_T;
for t = T-1:-1:1
    S(t) = Psi(S(t+1),t+1);
    if psi(count) == 0
        error(message('stats:hmmviterbi:ZeroTransitionProbability', psi(t+1)));
    end
end

