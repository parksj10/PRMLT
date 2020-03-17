/*
 * File: hmmEM_initialize.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 17-Mar-2020 11:47:11
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "hmmEM.h"
#include "hmmSmoother_.h"
#include "hmmViterbi_.h"
#include "hmmEM_initialize.h"
#include "getTime.h"
#include "timeKeeper.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void hmmEM_initialize(void)
{
  rt_InitInfAndNaN(8U);
  savedTime_not_empty_init();
  freq_not_empty_init();
}

/*
 * File trailer for hmmEM_initialize.c
 *
 * [EOF]
 */
