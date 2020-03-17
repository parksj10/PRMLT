/*
 * File: getTime.c
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
#include "getTime.h"
#include <windows.h>

/* Type Definitions */

/* Variable Definitions */
static double freq;
static boolean_T freq_not_empty;

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void freq_not_empty_init(void)
{
  freq_not_empty = false;
}

/*
 * Arguments    : double *t_tv_sec
 *                double *t_tv_nsec
 * Return Type  : void
 */
void getTime(double *t_tv_sec, double *t_tv_nsec)
{
  LARGE_INTEGER freqL;
  double timeRemainder;
  boolean_T rEQ0;
  double q;
  if (!freq_not_empty) {
    QueryPerformanceFrequency(&freqL);
    freq = (double)freqL.QuadPart;
    freq_not_empty = true;
  }

  QueryPerformanceCounter(&freqL);
  timeRemainder = (double)freqL.QuadPart;
  if (freq == 0.0) {
    if ((double)freqL.QuadPart == 0.0) {
      timeRemainder = freq;
    }
  } else if (rtIsNaN((double)freqL.QuadPart) || rtIsNaN(freq) || rtIsInf((double)
              freqL.QuadPart)) {
    timeRemainder = rtNaN;
  } else if ((double)freqL.QuadPart == 0.0) {
    timeRemainder = 0.0 / freq;
  } else if (rtIsInf(freq)) {
    if ((freq < 0.0) != ((double)freqL.QuadPart < 0.0)) {
      timeRemainder = freq;
    }
  } else {
    timeRemainder = fmod((double)freqL.QuadPart, freq);
    rEQ0 = (timeRemainder == 0.0);
    if ((!rEQ0) && (freq > floor(freq))) {
      q = fabs((double)freqL.QuadPart / freq);
      rEQ0 = (fabs(q - floor(q + 0.5)) <= 2.2204460492503131E-16 * q);
    }

    if (rEQ0) {
      timeRemainder = freq * 0.0;
    } else {
      if (((double)freqL.QuadPart < 0.0) != (freq < 0.0)) {
        timeRemainder += freq;
      }
    }
  }

  *t_tv_sec = ((double)freqL.QuadPart - timeRemainder) / freq;
  *t_tv_nsec = timeRemainder * 1.0E+9 / freq;
}

/*
 * File trailer for getTime.c
 *
 * [EOF]
 */
