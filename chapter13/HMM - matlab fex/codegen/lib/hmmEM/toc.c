/*
 * File: toc.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 17-Mar-2020 11:47:11
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "hmmEM.h"
#include "hmmSmoother_.h"
#include "hmmViterbi_.h"
#include "toc.h"
#include "getTime.h"
#include "timeKeeper.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : double
 */
double toc(void)
{
  double tstart_tv_sec;
  double tstart_tv_nsec;
  double tnow_tv_sec;
  double tnow_tv_nsec;
  b_timeKeeper(&tstart_tv_sec, &tstart_tv_nsec);
  getTime(&tnow_tv_sec, &tnow_tv_nsec);
  return (tnow_tv_sec - tstart_tv_sec) + (tnow_tv_nsec - tstart_tv_nsec) /
    1.0E+9;
}

/*
 * File trailer for toc.c
 *
 * [EOF]
 */
