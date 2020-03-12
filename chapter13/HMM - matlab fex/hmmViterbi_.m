function [z, p] = hmmViterbi_(O, A, B, s)
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
        psi(i,t) = psi_max;
        % update probability
        P(i) = B(i,O(t)) + delta_max;
    end
end
[v,idx] = max(v);
z = Z(idx,:);
p = exp(v);



pTR = zeros(numStates,L);
% assumption is that model is in state 1 at step 0
v = -Inf(numStates,1);
v(1,1) = 0;
vOld = v;

% loop through the model
for count = 1:L
    for state = 1:numStates
        % for each state we calculate
        % v(state) = e(state,seq(count))* max_k(vOld(:)*tr(k,state));
        bestVal = -inf;
        bestPTR = 0;
        % use a loop to avoid lots of calls to max
        for inner = 1:numStates 
            val = vOld(inner) + logTR(inner,state);
            if val > bestVal
                bestVal = val;
                bestPTR = inner;
            end
        end
        % save the best transition information for later backtracking
        pTR(state,count) = bestPTR;
        % update v
        v(state) = logE(state,seq(count)) + bestVal;
    end
    vOld = v;
end

% decide which of the final states is post probable
[logP, finalState] = max(v);

% Now back trace through the model
currentState(L) = finalState;
for count = L-1:-1:1
    currentState(count) = pTR(currentState(count+1),count+1);
    if currentState(count) == 0
        error(message('stats:hmmviterbi:ZeroTransitionProbability', currentState( count + 1 )));
    end
end