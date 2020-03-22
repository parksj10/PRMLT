/*
 * hmmEM.h
 *
 * Code generation for function 'hmmEM'
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
void hmmEM(const emlrtStack *sp, const emxArray_real_T *O, struct0_T *lambda,
           real_T maxIter, real_T tol, emxArray_real_T *llh);

/* End of code generation (hmmEM.h) */
