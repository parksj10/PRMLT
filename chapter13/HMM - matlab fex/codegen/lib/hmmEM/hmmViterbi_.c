/*
 * File: hmmViterbi_.c
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
#include "log.h"
#include <stdio.h>

/* Function Definitions */

/*
 * Implmentation function of Viterbi algorithm.
 *  Input:
 *    O: 1 x T observation sequence
 *    A: k x k transition matrix
 *    B: N x M emmision data matrix
 *    s: k x 1 starting probability (prior)
 *  Output:
 *    z: 1 x n latent state
 *    p: 1 x n probability
 *  Written by Josh Parks
 * Arguments    : const emxArray_real_T *O
 *                const struct0_T *lambda
 *                emxArray_real_T *S
 *                double *logP
 * Return Type  : void
 */
void hmmViterbi_(const emxArray_real_T *O, const struct0_T *lambda,
                 emxArray_real_T *S, double *logP)
{
  emxArray_real_T *pi;
  int i1;
  int nx;
  emxArray_real_T *logA;
  int N;
  emxArray_real_T *logB;
  int k;
  int b_O;
  emxArray_real_T *psi;
  double delta_max;
  double delta_temp;
  boolean_T exitg1;
  emxInit_real_T(&pi, 1);
  i1 = pi->size[0];
  pi->size[0] = lambda->pi->size[0];
  emxEnsureCapacity_real_T(pi, i1);
  nx = lambda->pi->size[0];
  for (i1 = 0; i1 < nx; i1++) {
    pi->data[i1] = lambda->pi->data[i1];
  }

  emxInit_real_T(&logA, 2);
  N = lambda->A->size[0] - 1;
  i1 = logA->size[0] * logA->size[1];
  logA->size[0] = lambda->A->size[0];
  logA->size[1] = lambda->A->size[1];
  emxEnsureCapacity_real_T(logA, i1);
  nx = lambda->A->size[0] * lambda->A->size[1];
  for (i1 = 0; i1 < nx; i1++) {
    logA->data[i1] = lambda->A->data[i1];
  }

  emxInit_real_T(&logB, 2);
  b_log(logA);
  i1 = logB->size[0] * logB->size[1];
  logB->size[0] = lambda->B->size[0];
  logB->size[1] = lambda->B->size[1];
  emxEnsureCapacity_real_T(logB, i1);
  nx = lambda->B->size[0] * lambda->B->size[1];
  for (i1 = 0; i1 < nx; i1++) {
    logB->data[i1] = lambda->B->data[i1];
  }

  b_log(logB);
  nx = lambda->pi->size[0];
  for (k = 0; k < nx; k++) {
    pi->data[k] = log(pi->data[k]);
  }

  b_O = (int)O->data[0];
  i1 = pi->size[0];
  emxEnsureCapacity_real_T(pi, i1);
  nx = pi->size[0];
  for (i1 = 0; i1 < nx; i1++) {
    pi->data[i1] += logB->data[i1 + logB->size[0] * (b_O - 1)];
  }

  emxInit_real_T(&psi, 2);
  i1 = psi->size[0] * psi->size[1];
  psi->size[0] = lambda->A->size[0];
  psi->size[1] = O->size[1];
  emxEnsureCapacity_real_T(psi, i1);
  nx = lambda->A->size[0] * O->size[1];
  for (i1 = 0; i1 < nx; i1++) {
    psi->data[i1] = 0.0;
  }

  /*  actually this is log(delta) --> phi, but leave as  */
  /*    delta for clarity (phi != psi) */
  i1 = S->size[0] * S->size[1];
  S->size[0] = 1;
  S->size[1] = O->size[1];
  emxEnsureCapacity_real_T(S, i1);
  nx = O->size[1];
  for (i1 = 0; i1 < nx; i1++) {
    S->data[i1] = 0.0;
  }

  /*  initialization */
  /*  decode all time points */
  i1 = O->size[1];
  for (k = 0; k <= i1 - 2; k++) {
    for (nx = 0; nx <= N; nx++) {
      /*  avoid max with loop */
      delta_max = rtMinusInf;
      psi->data[nx + psi->size[0] * (1 + k)] = 0.0;
      for (b_O = 0; b_O <= N; b_O++) {
        delta_temp = pi->data[b_O] + logA->data[b_O + logA->size[0] * nx];
        if (delta_temp > delta_max) {
          delta_max = delta_temp;
          psi->data[nx + psi->size[0] * (1 + k)] = 1.0 + (double)b_O;
        }
      }

      /*  save best state for backtracking */
      /*  update probability */
      pi->data[nx] = logB->data[nx + logB->size[0] * ((int)O->data[1 + k] - 1)]
        + delta_max;
    }
  }

  emxFree_real_T(&logB);
  emxFree_real_T(&logA);

  /* decide final state from max P */
  nx = pi->size[0];
  if (pi->size[0] <= 2) {
    if (pi->size[0] == 1) {
      delta_max = pi->data[0];
      b_O = 1;
    } else if ((pi->data[0] < pi->data[1]) || (rtIsNaN(pi->data[0]) && (!rtIsNaN
                 (pi->data[1])))) {
      delta_max = pi->data[1];
      b_O = 2;
    } else {
      delta_max = pi->data[0];
      b_O = 1;
    }
  } else {
    if (!rtIsNaN(pi->data[0])) {
      b_O = 1;
    } else {
      b_O = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= pi->size[0])) {
        if (!rtIsNaN(pi->data[k - 1])) {
          b_O = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (b_O == 0) {
      delta_max = pi->data[0];
      b_O = 1;
    } else {
      delta_max = pi->data[b_O - 1];
      i1 = b_O + 1;
      for (k = i1; k <= nx; k++) {
        if (delta_max < pi->data[k - 1]) {
          delta_max = pi->data[k - 1];
          b_O = k;
        }
      }
    }
  }

  emxFree_real_T(&pi);
  S->data[O->size[1] - 1] = b_O;

  /*  Now back trace through the model */
  i1 = (int)((1.0 + (-1.0 - ((double)O->size[1] - 1.0))) / -1.0);
  for (k = 0; k < i1; k++) {
    nx = (O->size[1] - k) - 1;
    S->data[nx - 1] = psi->data[((int)S->data[nx] + psi->size[0] * nx) - 1];
    if (psi->data[((int)S->data[nx] + psi->size[0] * nx) - 1] == 0.0) {
      printf("Error: transition probability equals 0, needs more input data");
      fflush(stdout);
    }
  }

  emxFree_real_T(&psi);
  *logP = delta_max;
}

/*
 * File trailer for hmmViterbi_.c
 *
 * [EOF]
 */
