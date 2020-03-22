/*
 * File: hmmEM.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 20-Mar-2020 21:34:12
 */

#ifndef HMMEM_H
#define HMMEM_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "hmmEM_types.h"

/* Type Definitions */
#include <windows.h>

/* Variable Declarations */
extern rtRunTimeErrorInfo e_emlrtRTEI;

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void hmmEM(const emxArray_real_T *O, struct0_T *lambda, double maxIter,
                    double tol, emxArray_real_T *llh);
  extern void hmmEM_initialize(void);
  extern void hmmEM_terminate(void);
  extern void hmmViterbi(const emxArray_real_T *O, const struct0_T *lambda,
    emxArray_real_T *S, double *logP);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for hmmEM.h
 *
 * [EOF]
 */
