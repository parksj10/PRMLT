/*
 * hmmViterbi.h
 *
 * Code generation for function 'hmmViterbi'
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
#include "hmmViterbi_types.h"

/* Function Declarations */
void hmmViterbi(const emlrtStack *sp, const emxArray_real_T *O, const struct0_T *
                lambda, emxArray_real_T *S, real_T *logP);

/* End of code generation (hmmViterbi.h) */
