/*
 * timeKeeper.h
 *
 * Code generation for function 'timeKeeper'
 *
 */

#pragma once

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "hmmEM_types.h"

/* Function Declarations */
void b_timeKeeper(const emlrtStack *sp, real_T *outTime_tv_sec, real_T
                  *outTime_tv_nsec);
void savedTime_not_empty_init(void);
void timeKeeper(const emlrtStack *sp, real_T newTime_tv_sec, real_T
                newTime_tv_nsec);

/* End of code generation (timeKeeper.h) */
