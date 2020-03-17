/*
 * File: main.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 17-Mar-2020 11:47:11
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "hmmEM.h"
#include "hmmSmoother_.h"
#include "hmmViterbi_.h"
#include "main.h"
#include "hmmEM_terminate.h"
#include "hmmEM_emxAPI.h"
#include "hmmEM_initialize.h"

/* Function Declarations */
static emxArray_real_T *argInit_1xUnbounded_real_T(void);
static emxArray_real_T *argInit_Unboundedx1_real_T(void);
static double argInit_real_T(void);
static struct0_T argInit_struct0_T(void);
static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void);
static void main_hmmEM(void);
static void main_hmmSmoother_(void);
static void main_hmmViterbi_(void);

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_1xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_real_T(1, 2);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx1] = argInit_real_T();
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_Unboundedx1_real_T(void)
{
  emxArray_real_T *result;
  static int iv0[1] = { 2 };

  int idx0;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, iv0);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0] = argInit_real_T();
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : struct0_T
 */
static struct0_T argInit_struct0_T(void)
{
  struct0_T result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result.A = c_argInit_UnboundedxUnbounded_r();
  result.B = c_argInit_UnboundedxUnbounded_r();
  result.pi = argInit_Unboundedx1_real_T();
  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void)
{
  emxArray_real_T *result;
  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_real_T(2, 2);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_hmmEM(void)
{
  emxArray_real_T *llh;
  emxArray_real_T *O;
  struct0_T lambda;
  emxInitArray_real_T(&llh, 2);

  /* Initialize function 'hmmEM' input arguments. */
  /* Initialize function input argument 'O'. */
  O = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'lambda'. */
  lambda = argInit_struct0_T();

  /* Call the entry-point 'hmmEM'. */
  hmmEM(O, &lambda, argInit_real_T(), argInit_real_T(), llh);
  emxDestroyArray_real_T(llh);
  emxDestroy_struct0_T(lambda);
  emxDestroyArray_real_T(O);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_hmmSmoother_(void)
{
  emxArray_real_T *b_gamma;
  emxArray_real_T *epsilon;
  emxArray_real_T *alpha;
  emxArray_real_T *beta;
  emxArray_real_T *c;
  emxArray_real_T *O;
  struct0_T lambda;
  emxInitArray_real_T(&b_gamma, 2);
  emxInitArray_real_T(&epsilon, 3);
  emxInitArray_real_T(&alpha, 2);
  emxInitArray_real_T(&beta, 2);
  emxInitArray_real_T(&c, 2);

  /* Initialize function 'hmmSmoother_' input arguments. */
  /* Initialize function input argument 'O'. */
  O = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'lambda'. */
  lambda = argInit_struct0_T();

  /* Call the entry-point 'hmmSmoother_'. */
  hmmSmoother_(O, &lambda, b_gamma, epsilon, alpha, beta, c);
  emxDestroyArray_real_T(c);
  emxDestroyArray_real_T(beta);
  emxDestroyArray_real_T(alpha);
  emxDestroyArray_real_T(epsilon);
  emxDestroyArray_real_T(b_gamma);
  emxDestroy_struct0_T(lambda);
  emxDestroyArray_real_T(O);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_hmmViterbi_(void)
{
  emxArray_real_T *S;
  emxArray_real_T *O;
  struct0_T lambda;
  double logP;
  emxInitArray_real_T(&S, 2);

  /* Initialize function 'hmmViterbi_' input arguments. */
  /* Initialize function input argument 'O'. */
  O = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'lambda'. */
  lambda = argInit_struct0_T();

  /* Call the entry-point 'hmmViterbi_'. */
  hmmViterbi_(O, &lambda, S, &logP);
  emxDestroyArray_real_T(S);
  emxDestroy_struct0_T(lambda);
  emxDestroyArray_real_T(O);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  hmmEM_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_hmmEM();
  main_hmmSmoother_();
  main_hmmViterbi_();

  /* Terminate the application.
     You do not need to do this more than one time. */
  hmmEM_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
