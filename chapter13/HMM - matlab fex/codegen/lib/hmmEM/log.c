/*
 * File: log.c
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
#include "log.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *x
 * Return Type  : void
 */
void b_log(emxArray_real_T *x)
{
  int nx;
  int k;
  nx = x->size[0] * x->size[1];
  for (k = 0; k < nx; k++) {
    x->data[k] = log(x->data[k]);
  }
}

/*
 * File trailer for log.c
 *
 * [EOF]
 */
