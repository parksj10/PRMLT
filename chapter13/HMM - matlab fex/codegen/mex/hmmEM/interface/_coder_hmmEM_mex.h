/*
 * _coder_hmmEM_mex.h
 *
 * Code generation for function '_coder_hmmEM_mex'
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
MEXFUNCTION_LINKAGE void hmmEM_mexFunction(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[4]);
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
  const mxArray *prhs[]);
emlrtCTX mexFunctionCreateRootTLS(void);

/* End of code generation (_coder_hmmEM_mex.h) */
