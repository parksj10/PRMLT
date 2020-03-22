/*
 * hmmSmoother.h
 *
 * Code generation for function 'hmmSmoother'
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
void hmmSmoother(const emlrtStack *sp, const emxArray_real_T *O, const
                 emxArray_real_T *lambda_A, const emxArray_real_T *lambda_B,
                 const emxArray_real_T *lambda_pi, emxArray_real_T *b_gamma,
                 emxArray_real_T *xi, emxArray_real_T *c);

/* End of code generation (hmmSmoother.h) */
