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

% init with a model
A = lambda.A;
B = lambda.B;
T = numel(O);
pi = lambda.pi;
[N, M] = size(B);

iters = 0;
llh = zeros(1,maxIter);
%loop over maxIter
for Q = 1:maxIter
    
    tic;
    % determine parameters
    [gamma, epsilon, alpha, beta, c] = hmmSmoother_(O, lambda);
    rt = toc;
    fprintf('Smoother took %f seconds on interation %d \n', rt, Q)
    
    
    % re-estimate pi
    for i = 1:N
        pi(i) = gamma(i,1);
    end

    % re-estimate A
    for i = 1:N
        denom = 0;
        for t = 1:T-1
            denom = denom + gamma(i,t);
        end %t
        for j = 1:N
            numer = 0;
            for t = 1:T-1
                numer = numer + epsilon(i,j,t);
            end %t
            A(i,j) = numer/denom;
        end %j
    end %i

    % re-estimate B
    for j = 1:N
        denom = 0;
        for t = 1:T
            denom = denom + gamma(j,t);
        end %t
        for k = 1:M
            numer = 0;
            for t = 1:T
                if(O(t) == k)
                    numer = numer + gamma(j,t);
                end
            end %t
            B(j,k) = numer/denom;
        end %k
    end %i

    % compute log(P(O|lambda))
    for t = 1:T
        llh(Q) = llh(Q) + log(c(t));
    end %t
    llh(Q) = -llh(Q);
    
    % iteration complete
    iters = iters + 1;
    lambda.A = A;
    lambda.B = B;
    lambda.pi = pi;
    
    % break when tolerance or maxIter is reached
    if (iters >= maxIter)
        return;
    elseif Q ~=1 && (llh(Q) < llh(Q-1) || abs(-llh(Q) + llh(Q-1)) <= tol)
        return;
    end
    
end %iter



