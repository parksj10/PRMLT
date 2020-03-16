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
delta = zeros(N,T); % actually this is log(delta) --> phi, but leave as 
                    %   delta for clarity (phi != psi)
S = zeros(1,T);

% initialization
delta(:,1) = P;

% decode all time points
for t = 2:T
    for j = 1:N
        % avoid max with loop
        delta_max = -inf;
        psi_max = 0;
        for i = 1:N
            delta_temp = P(i) + logA(i,j);
            if delta_temp > delta_max
                delta_max = delta_temp;
                psi_max = i;
            end 
        end
        % save best state for backtracking
        delta(j,t) = delta_max;
        psi(j,t) = psi_max;
        % update probability
        P(j) = logB(j,O(t)) + delta_max;
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
stop;
