/*
 * File: hmmSmoother_.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 17-Mar-2020 11:47:11
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "hmmEM.h"
#include "hmmSmoother_.h"
#include "hmmViterbi_.h"
#include "hmmEM_emxutil.h"

/* Function Definitions */

/*
 * Implmentation function HMM smoothing alogrithm.
 *  Unlike the method described in the book of PRML, the alpha returned is the normalized version: gamma(t)=p(z_t|x_{1:T})
 *  Computing unnormalized version gamma(t)=p(z_t,x_{1:T}) is numerical unstable, which grows exponential fast to infinity.
 *  Input:
 *    O:  1 x T observation matrix
 *    A:  N x N transition probability matrix
 *    B:  M x N emission probability matrix
 *    pi: N x 1 start prior probability
 *  Output:
 *    gamma:   N x T      smoothed node marginals gamma(i,t)=p(O1:Ot, s_i | lambda)
 *    epsilon: N x N x T  smoothed edge marginals epsilon(i,j,t)=p(s_i, s_j | O, lambda)
 *    alpha: k x n matrix of posterior alpha(t)=p(z_t|x_{1:T})
 *    beta: k x n matrix of posterior beta(t)=gamma(t)/alpha(t)
 *    c: loglikelihood
 *  Written by Mo Chen (sth4nth@gmail.com).
 * Arguments    : const emxArray_real_T *O
 *                const struct0_T *lambda
 *                emxArray_real_T *b_gamma
 *                emxArray_real_T *epsilon
 *                emxArray_real_T *alpha
 *                emxArray_real_T *beta
 *                emxArray_real_T *c
 * Return Type  : void
 */
void hmmSmoother_(const emxArray_real_T *O, const struct0_T *lambda,
                  emxArray_real_T *b_gamma, emxArray_real_T *epsilon,
                  emxArray_real_T *alpha, emxArray_real_T *beta, emxArray_real_T
                  *c)
{
  int T;
  int N;
  int i0;
  int loop_ub;
  int t;
  int j;
  int b_t;
  T = O->size[1] - 1;
  N = lambda->A->size[0] - 1;
  i0 = c->size[0] * c->size[1];
  c->size[0] = 1;
  c->size[1] = O->size[1];
  emxEnsureCapacity_real_T(c, i0);
  loop_ub = O->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    c->data[i0] = 0.0;
  }

  /*  normalization constant */
  /*  alpha calc */
  i0 = alpha->size[0] * alpha->size[1];
  alpha->size[0] = lambda->A->size[0];
  alpha->size[1] = O->size[1];
  emxEnsureCapacity_real_T(alpha, i0);
  loop_ub = lambda->A->size[0] * O->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    alpha->data[i0] = 0.0;
  }

  /* alpha_1 */
  i0 = lambda->A->size[0];
  for (loop_ub = 0; loop_ub < i0; loop_ub++) {
    alpha->data[loop_ub] = lambda->pi->data[loop_ub] * lambda->B->data[lambda->
      B->size[0] * ((int)O->data[0] - 1)];
    c->data[0] += alpha->data[loop_ub];
  }

  /* scale alpha_1 */
  c->data[0] = 1.0 / c->data[0];
  i0 = lambda->A->size[0];
  for (loop_ub = 0; loop_ub < i0; loop_ub++) {
    alpha->data[loop_ub] *= c->data[0];
  }

  /* compute alpha_t(i) */
  i0 = O->size[1];
  for (t = 0; t <= i0 - 2; t++) {
    c->data[1 + t] = 0.0;
    for (j = 0; j <= N; j++) {
      alpha->data[j + alpha->size[0] * (1 + t)] = 0.0;

      /* initialize alpha_t(j) */
      for (loop_ub = 0; loop_ub <= N; loop_ub++) {
        alpha->data[j + alpha->size[0] * (1 + t)] += alpha->data[loop_ub +
          alpha->size[0] * t] * lambda->A->data[loop_ub + lambda->A->size[0] * j];
      }

      /* i */
      alpha->data[j + alpha->size[0] * (1 + t)] *= lambda->B->data[j + lambda->
        B->size[0] * ((int)O->data[1 + t] - 1)];
      c->data[1 + t] += alpha->data[j + alpha->size[0] * (1 + t)];
    }

    /* j */
    /* scale alpha_t */
    c->data[1 + t] = 1.0 / c->data[1 + t];
    for (j = 0; j <= N; j++) {
      alpha->data[j + alpha->size[0] * (1 + t)] *= c->data[1 + t];
    }
  }

  /* t */
  /*  beta calc */
  i0 = beta->size[0] * beta->size[1];
  beta->size[0] = lambda->A->size[0];
  beta->size[1] = O->size[1];
  emxEnsureCapacity_real_T(beta, i0);
  loop_ub = lambda->A->size[0] * O->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    beta->data[i0] = 0.0;
  }

  /* beta_T scaling */
  i0 = lambda->A->size[0];
  for (loop_ub = 0; loop_ub < i0; loop_ub++) {
    beta->data[loop_ub + beta->size[0] * T] = c->data[T];

    /*  initialization says beta_T = 1 */
  }

  /* beta_t(i) */
  i0 = (int)((1.0 + (-1.0 - ((double)O->size[1] - 1.0))) / -1.0);
  for (t = 0; t < i0; t++) {
    b_t = (T - t) - 1;
    for (loop_ub = 0; loop_ub <= N; loop_ub++) {
      beta->data[loop_ub + beta->size[0] * b_t] = 0.0;
      for (j = 0; j <= N; j++) {
        beta->data[loop_ub + beta->size[0] * b_t] += lambda->A->data[loop_ub +
          lambda->A->size[0] * j] * lambda->B->data[j + lambda->B->size[0] *
          ((int)O->data[b_t + 1] - 1)] * beta->data[j + beta->size[0] * (b_t + 1)];
      }

      /* j */
      /* scale beta_t with same c_t as alpha_t */
      beta->data[loop_ub + beta->size[0] * b_t] *= c->data[b_t];
    }

    /* i */
  }

  /* t */
  /* compute epsilon_t and gamma_t (no need to normalize, alpha and beta are scaled) */
  i0 = epsilon->size[0] * epsilon->size[1] * epsilon->size[2];
  epsilon->size[0] = lambda->A->size[0];
  epsilon->size[1] = lambda->A->size[0];
  epsilon->size[2] = O->size[1] - 1;
  emxEnsureCapacity_real_T(epsilon, i0);
  loop_ub = lambda->A->size[0] * lambda->A->size[0] * (O->size[1] - 1);
  for (i0 = 0; i0 < loop_ub; i0++) {
    epsilon->data[i0] = 0.0;
  }

  /* also called "di-gamma" */
  i0 = b_gamma->size[0] * b_gamma->size[1];
  b_gamma->size[0] = lambda->A->size[0];
  b_gamma->size[1] = O->size[1];
  emxEnsureCapacity_real_T(b_gamma, i0);
  loop_ub = lambda->A->size[0] * O->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_gamma->data[i0] = 0.0;
  }

  i0 = O->size[1];
  for (t = 0; t <= i0 - 2; t++) {
    for (loop_ub = 0; loop_ub <= N; loop_ub++) {
      b_gamma->data[loop_ub + b_gamma->size[0] * t] = 0.0;
      for (j = 0; j <= N; j++) {
        epsilon->data[(loop_ub + epsilon->size[0] * j) + epsilon->size[0] *
          epsilon->size[1] * t] = alpha->data[loop_ub + alpha->size[0] * t] *
          lambda->A->data[loop_ub + lambda->A->size[0] * j] * lambda->B->data[j
          + lambda->B->size[0] * ((int)O->data[t + 1] - 1)] * beta->data[j +
          beta->size[0] * (t + 1)];
        b_gamma->data[loop_ub + b_gamma->size[0] * t] += epsilon->data[(loop_ub
          + epsilon->size[0] * j) + epsilon->size[0] * epsilon->size[1] * t];
      }

      /* j */
    }

    /* i */
  }

  /* t */
  /* special case gamma */
  i0 = lambda->A->size[0];
  for (loop_ub = 0; loop_ub < i0; loop_ub++) {
    b_gamma->data[loop_ub + b_gamma->size[0] * T] = alpha->data[loop_ub +
      alpha->size[0] * T];
  }
}

/*
 * File trailer for hmmSmoother_.c
 *
 * [EOF]
 */
