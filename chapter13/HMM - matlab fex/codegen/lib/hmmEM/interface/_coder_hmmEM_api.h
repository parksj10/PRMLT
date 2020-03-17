/*
 * File: _coder_hmmEM_api.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 17-Mar-2020 11:47:11
 */

#ifndef _CODER_HMMEM_API_H
#define _CODER_HMMEM_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_hmmEM_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  emxArray_real_T *A;
  emxArray_real_T *B;
  emxArray_real_T *pi;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void hmmEM(emxArray_real_T *O, struct0_T *lambda, real_T maxIter, real_T
                  tol, emxArray_real_T *llh);
extern void hmmEM_api(const mxArray * const prhs[4], int32_T nlhs, const mxArray
                      *plhs[2]);
extern void hmmEM_atexit(void);
extern void hmmEM_initialize(void);
extern void hmmEM_terminate(void);
extern void hmmEM_xil_shutdown(void);
extern void hmmEM_xil_terminate(void);
extern void hmmSmoother_(emxArray_real_T *O, struct0_T *lambda, emxArray_real_T *
  b_gamma, emxArray_real_T *epsilon, emxArray_real_T *alpha, emxArray_real_T
  *beta, emxArray_real_T *c);
extern void hmmSmoother__api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[5]);
extern void hmmViterbi_(emxArray_real_T *O, struct0_T *lambda, emxArray_real_T
  *S, real_T *logP);
extern void hmmViterbi__api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[2]);

#endif

/*
 * File trailer for _coder_hmmEM_api.h
 *
 * [EOF]
 */
