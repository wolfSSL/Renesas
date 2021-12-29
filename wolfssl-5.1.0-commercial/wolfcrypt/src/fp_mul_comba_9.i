/* fp_mul_comba_9.i
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifdef TFM_MUL9
int fp_mul_comba9(fp_int *A, fp_int *B, fp_int *C)
{
   fp_digit c0, c1, c2;
#ifndef WOLFSSL_SMALL_STACK
   fp_digit at[18];
#else
   fp_digit *at;
#endif

#ifdef WOLFSSL_SMALL_STACK
   at = (fp_digit*)XMALLOC(sizeof(fp_digit) * 18, NULL, DYNAMIC_TYPE_TMP_BUFFER);
   if (at == NULL)
       return FP_MEM;
#endif

   XMEMCPY(at, A->dp, 9 * sizeof(fp_digit));
   XMEMCPY(at+9, B->dp, 9 * sizeof(fp_digit));
   COMBA_START;

   COMBA_CLEAR;
   /* 0 */
   MULADD(at[0], at[9]); 
   COMBA_STORE(C->dp[0]);
   /* 1 */
   COMBA_FORWARD;
   MULADD(at[0], at[10]);    MULADD(at[1], at[9]); 
   COMBA_STORE(C->dp[1]);
   /* 2 */
   COMBA_FORWARD;
   MULADD(at[0], at[11]);    MULADD(at[1], at[10]);    MULADD(at[2], at[9]); 
   COMBA_STORE(C->dp[2]);
   /* 3 */
   COMBA_FORWARD;
   MULADD(at[0], at[12]);    MULADD(at[1], at[11]);    MULADD(at[2], at[10]);    MULADD(at[3], at[9]); 
   COMBA_STORE(C->dp[3]);
   /* 4 */
   COMBA_FORWARD;
   MULADD(at[0], at[13]);    MULADD(at[1], at[12]);    MULADD(at[2], at[11]);    MULADD(at[3], at[10]);    MULADD(at[4], at[9]); 
   COMBA_STORE(C->dp[4]);
   /* 5 */
   COMBA_FORWARD;
   MULADD(at[0], at[14]);    MULADD(at[1], at[13]);    MULADD(at[2], at[12]);    MULADD(at[3], at[11]);    MULADD(at[4], at[10]);    MULADD(at[5], at[9]); 
   COMBA_STORE(C->dp[5]);
   /* 6 */
   COMBA_FORWARD;
   MULADD(at[0], at[15]);    MULADD(at[1], at[14]);    MULADD(at[2], at[13]);    MULADD(at[3], at[12]);    MULADD(at[4], at[11]);    MULADD(at[5], at[10]);    MULADD(at[6], at[9]); 
   COMBA_STORE(C->dp[6]);
   /* 7 */
   COMBA_FORWARD;
   MULADD(at[0], at[16]);    MULADD(at[1], at[15]);    MULADD(at[2], at[14]);    MULADD(at[3], at[13]);    MULADD(at[4], at[12]);    MULADD(at[5], at[11]);    MULADD(at[6], at[10]);    MULADD(at[7], at[9]); 
   COMBA_STORE(C->dp[7]);
   /* 8 */
   COMBA_FORWARD;
   MULADD(at[0], at[17]);    MULADD(at[1], at[16]);    MULADD(at[2], at[15]);    MULADD(at[3], at[14]);    MULADD(at[4], at[13]);    MULADD(at[5], at[12]);    MULADD(at[6], at[11]);    MULADD(at[7], at[10]);    MULADD(at[8], at[9]); 
   COMBA_STORE(C->dp[8]);
   /* 9 */
   COMBA_FORWARD;
   MULADD(at[1], at[17]);    MULADD(at[2], at[16]);    MULADD(at[3], at[15]);    MULADD(at[4], at[14]);    MULADD(at[5], at[13]);    MULADD(at[6], at[12]);    MULADD(at[7], at[11]);    MULADD(at[8], at[10]); 
   COMBA_STORE(C->dp[9]);
   /* 10 */
   COMBA_FORWARD;
   MULADD(at[2], at[17]);    MULADD(at[3], at[16]);    MULADD(at[4], at[15]);    MULADD(at[5], at[14]);    MULADD(at[6], at[13]);    MULADD(at[7], at[12]);    MULADD(at[8], at[11]); 
   COMBA_STORE(C->dp[10]);
   /* 11 */
   COMBA_FORWARD;
   MULADD(at[3], at[17]);    MULADD(at[4], at[16]);    MULADD(at[5], at[15]);    MULADD(at[6], at[14]);    MULADD(at[7], at[13]);    MULADD(at[8], at[12]); 
   COMBA_STORE(C->dp[11]);
   /* 12 */
   COMBA_FORWARD;
   MULADD(at[4], at[17]);    MULADD(at[5], at[16]);    MULADD(at[6], at[15]);    MULADD(at[7], at[14]);    MULADD(at[8], at[13]); 
   COMBA_STORE(C->dp[12]);
   /* 13 */
   COMBA_FORWARD;
   MULADD(at[5], at[17]);    MULADD(at[6], at[16]);    MULADD(at[7], at[15]);    MULADD(at[8], at[14]); 
   COMBA_STORE(C->dp[13]);
   /* 14 */
   COMBA_FORWARD;
   MULADD(at[6], at[17]);    MULADD(at[7], at[16]);    MULADD(at[8], at[15]); 
   COMBA_STORE(C->dp[14]);
   /* 15 */
   COMBA_FORWARD;
   MULADD(at[7], at[17]);    MULADD(at[8], at[16]); 
   COMBA_STORE(C->dp[15]);
   /* 16 */
   COMBA_FORWARD;
   MULADD(at[8], at[17]); 
   COMBA_STORE(C->dp[16]);
   COMBA_STORE2(C->dp[17]);
   C->used = 18;
   C->sign = A->sign ^ B->sign;
   fp_clamp(C);
   COMBA_FINI;

#ifdef WOLFSSL_SMALL_STACK
   XFREE(at, NULL, DYNAMIC_TYPE_TMP_BUFFER);
#endif
   return FP_OKAY;
}
#endif
