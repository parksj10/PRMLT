/*
 * File: hmmEM_emxAPI.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 20-Mar-2020 21:34:12
 */

#ifndef HMMEM_EMXAPI_H
#define HMMEM_EMXAPI_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "hmmEM_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern emxArray_real_T *emxCreateND_real_T(int numDimensions, const int *size);
  extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
    numDimensions, const int *size);
  extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int
    cols);
  extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
  extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
  extern void emxDestroy_struct0_T(struct0_T emxArray);
  extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);
  extern void emxInit_struct0_T(struct0_T *pStruct);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for hmmEM_emxAPI.h
 *
 * [EOF]
 */
