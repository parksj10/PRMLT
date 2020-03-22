function [lambda, llh] = hmmEM(O, lambda, maxIter, tol)
% EM algorithm to fit the parameters of HMM model (a.k.a Baum-Welch algorithm)
% Input:
%   O: 1 x T observation matrix
%   lambda: model containing A, B, pi
%   maxIter: maximum number of E/M iterations
%   tol: tolerance between E/M steps (minimum change in model), or finish
% Output:s
%   lambdaN: trained model containing A, B, pi
%   llh: loglikelihood of observation given model
% Written by Mo Chen (sth4nth@gmail.com).

% Prohibit inlining to reduce code size.
coder.inline('never');

T = numel(O);
Q = int32(0);
llh = zeros(1,maxIter);

% do until condition is met
while 1
    
    % iteration counter
    Q = Q + 1;
    
    tic;
    % determine parameters, Expectation step (E)
    [gamma, xi, c] = hmmSmoother(O, lambda);
    rt = toc;
    fprintf('Smoother took %.2f seconds on interation %d \n', rt, Q)
    
    tic
    % re-estimate parameters, Maximization step (M)
    [lambda.A, lambda.B, lambda.pi] = hmmReestimate(O, lambda, gamma, xi);
    rt = toc;
    fprintf('Baum Welch took %.2f seconds on interation %d \n', rt, Q)
    
    % compute log(P(O|lambda))
    for t = 1:T
        llh(Q) = llh(Q) + log(c(t));
    end %t
    llh(Q) = -llh(Q);
    
    % break when tolerance or maxIter is reached
    if (Q >= maxIter)
        return;
    elseif Q ~=1 && (llh(Q) < llh(Q-1) || abs(-llh(Q) + llh(Q-1)) <= tol)
        return;
    end
    
end %while



