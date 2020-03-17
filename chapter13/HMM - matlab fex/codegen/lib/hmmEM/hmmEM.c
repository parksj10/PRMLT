/*
 * File: hmmEM.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 17-Mar-2020 11:47:11
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "hmmEM.h"
#include "hmmSmoother_.h"
#include "hmmViterbi_.h"
#include "hmmEM_emxutil.h"
#include "toc.h"
#include "tic.h"
#include <stdio.h>

/* Function Definitions */

/*
 * EM algorithm to fit the parameters of HMM model (a.k.a Baum-Welch algorithm)
 *  Input:
 *    O: 1 x T observation matrix
 *    lambda: model containing A, B, pi
 *    maxIter: maximum number of E/M iterations
 *    tol: tolerance between E/M steps (minimum change in model), or finish
 *  Output:s
 *    lambdaN: trained model containing A, B, pi
 *    llh: loglikelihood of observation given model
 *  Written by Mo Chen (sth4nth@gmail.com).
 * Arguments    : const emxArray_real_T *O
 *                struct0_T *lambda
 *                double maxIter
 *                double tol
 *                emxArray_real_T *llh
 * Return Type  : void
 */
void hmmEM(const emxArray_real_T *O, struct0_T *lambda, double maxIter, double
           tol, emxArray_real_T *llh)
{
  emxArray_real_T *A;
  int i;
  int loop_ub;
  emxArray_real_T *B;
  emxArray_real_T *pi;
  int T;
  int M;
  int N;
  double iters;
  int Q;
  emxArray_real_T *b_gamma;
  emxArray_real_T *epsilon;
  emxArray_real_T *alpha;
  emxArray_real_T *beta;
  emxArray_real_T *c;
  boolean_T exitg1;
  double denom;
  int t;
  int j;
  double numer;
  int k;
  emxInit_real_T(&A, 2);

  /*  init with a model */
  i = A->size[0] * A->size[1];
  A->size[0] = lambda->A->size[0];
  A->size[1] = lambda->A->size[1];
  emxEnsureCapacity_real_T(A, i);
  loop_ub = lambda->A->size[0] * lambda->A->size[1];
  for (i = 0; i < loop_ub; i++) {
    A->data[i] = lambda->A->data[i];
  }

  emxInit_real_T(&B, 2);
  i = B->size[0] * B->size[1];
  B->size[0] = lambda->B->size[0];
  B->size[1] = lambda->B->size[1];
  emxEnsureCapacity_real_T(B, i);
  loop_ub = lambda->B->size[0] * lambda->B->size[1];
  for (i = 0; i < loop_ub; i++) {
    B->data[i] = lambda->B->data[i];
  }

  emxInit_real_T(&pi, 1);
  T = O->size[1] - 1;
  i = pi->size[0];
  pi->size[0] = lambda->pi->size[0];
  emxEnsureCapacity_real_T(pi, i);
  loop_ub = lambda->pi->size[0];
  for (i = 0; i < loop_ub; i++) {
    pi->data[i] = lambda->pi->data[i];
  }

  M = lambda->B->size[1] - 1;
  N = lambda->B->size[0] - 1;
  iters = 0.0;
  i = llh->size[0] * llh->size[1];
  llh->size[0] = 1;
  loop_ub = (int)maxIter;
  llh->size[1] = loop_ub;
  emxEnsureCapacity_real_T(llh, i);
  for (i = 0; i < loop_ub; i++) {
    llh->data[i] = 0.0;
  }

  /* loop over maxIter */
  Q = 0;
  emxInit_real_T(&b_gamma, 2);
  emxInit_real_T(&epsilon, 3);
  emxInit_real_T(&alpha, 2);
  emxInit_real_T(&beta, 2);
  emxInit_real_T(&c, 2);
  exitg1 = false;
  while ((!exitg1) && (Q <= loop_ub - 1)) {
    tic();

    /*  determine parameters, Expectation step (E) */
    hmmSmoother_(O, lambda, b_gamma, epsilon, alpha, beta, c);
    denom = toc();
    printf("Smoother took %f seconds on interation %.2f \n", denom, 1.0 +
           (double)Q);
    fflush(stdout);

    /*  re-estimate pi */
    for (i = 0; i <= N; i++) {
      pi->data[i] = b_gamma->data[i];
    }

    tic();

    /*  re-estimate A */
    for (i = 0; i <= N; i++) {
      denom = 0.0;
      for (t = 0; t < T; t++) {
        denom += b_gamma->data[i + b_gamma->size[0] * t];
      }

      /* t */
      for (j = 0; j <= N; j++) {
        numer = 0.0;
        for (t = 0; t < T; t++) {
          numer += epsilon->data[(i + epsilon->size[0] * j) + epsilon->size[0] *
            epsilon->size[1] * t];
        }

        /* t */
        A->data[i + A->size[0] * j] = numer / denom;
      }

      /* j */
    }

    /* i */
    /*  re-estimate B */
    for (j = 0; j <= N; j++) {
      denom = 0.0;
      for (t = 0; t <= T; t++) {
        denom += b_gamma->data[j + b_gamma->size[0] * t];
      }

      /* t */
      for (k = 0; k <= M; k++) {
        numer = 0.0;
        for (t = 0; t <= T; t++) {
          if (O->data[t] == 1.0 + (double)k) {
            numer += b_gamma->data[j + b_gamma->size[0] * t];
          }
        }

        /* t */
        B->data[j + B->size[0] * k] = numer / denom;
      }

      /* k */
    }

    /* i */
    /*  compute log(P(O|lambda)) */
    for (t = 0; t <= T; t++) {
      llh->data[Q] += log(c->data[t]);
    }

    /* t */
    llh->data[Q] = -llh->data[Q];

    /*  iteration complete */
    iters++;
    i = lambda->A->size[0] * lambda->A->size[1];
    lambda->A->size[0] = A->size[0];
    lambda->A->size[1] = A->size[1];
    emxEnsureCapacity_real_T(lambda->A, i);
    k = A->size[0] * A->size[1];
    for (i = 0; i < k; i++) {
      lambda->A->data[i] = A->data[i];
    }

    i = lambda->B->size[0] * lambda->B->size[1];
    lambda->B->size[0] = B->size[0];
    lambda->B->size[1] = B->size[1];
    emxEnsureCapacity_real_T(lambda->B, i);
    k = B->size[0] * B->size[1];
    for (i = 0; i < k; i++) {
      lambda->B->data[i] = B->data[i];
    }

    i = lambda->pi->size[0];
    lambda->pi->size[0] = pi->size[0];
    emxEnsureCapacity_real_T(lambda->pi, i);
    k = pi->size[0];
    for (i = 0; i < k; i++) {
      lambda->pi->data[i] = pi->data[i];
    }

    /*  break when tolerance or maxIter is reached */
    if ((iters >= maxIter) || ((1.0 + (double)Q != 1.0) && ((llh->data[Q] <
           llh->data[Q - 1]) || (fabs(-llh->data[Q] + llh->data[Q - 1]) <= tol))))
    {
      exitg1 = true;
    } else {
      denom = toc();
      printf("Baum Welch took %f seconds on interation %.2f \n", denom, 1.0 +
             (double)Q);
      fflush(stdout);
      Q++;
    }
  }

  emxFree_real_T(&c);
  emxFree_real_T(&beta);
  emxFree_real_T(&alpha);
  emxFree_real_T(&epsilon);
  emxFree_real_T(&b_gamma);
  emxFree_real_T(&pi);
  emxFree_real_T(&B);
  emxFree_real_T(&A);

  /* iter */
}

/*
 * File trailer for hmmEM.c
 *
 * [EOF]
 */
