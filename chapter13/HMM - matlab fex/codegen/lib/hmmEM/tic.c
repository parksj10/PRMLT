/*
 * File: tic.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 17-Mar-2020 11:47:11
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "hmmEM.h"
#include "hmmSmoother_.h"
#include "hmmViterbi_.h"
#include "tic.h"
#include "timeKeeper.h"
#include "getTime.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void tic(void)
{
  double t0_tv_sec;
  double t0_tv_nsec;
  getTime(&t0_tv_sec, &t0_tv_nsec);
  timeKeeper(t0_tv_sec, t0_tv_nsec);
}

/*
 * File trailer for tic.c
 *
 * [EOF]
 */
