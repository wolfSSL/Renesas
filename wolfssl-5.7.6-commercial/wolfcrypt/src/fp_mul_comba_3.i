/* fp_mul_comba_3.i
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifdef TFM_MUL3
int fp_mul_comba3(fp_int *A, fp_int *B, fp_int *C)
{
   fp_digit c0, c1, c2, at[6];

   XMEMCPY(at, A->dp, 3 * sizeof(fp_digit));
   XMEMCPY(at+3, B->dp, 3 * sizeof(fp_digit));
   COMBA_START;

   COMBA_CLEAR;
   /* 0 */
   MULADD(at[0], at[3]); 
   COMBA_STORE(C->dp[0]);
   /* 1 */
   COMBA_FORWARD;
   MULADD(at[0], at[4]);    MULADD(at[1], at[3]); 
   COMBA_STORE(C->dp[1]);
   /* 2 */
   COMBA_FORWARD;
   MULADD(at[0], at[5]);    MULADD(at[1], at[4]);    MULADD(at[2], at[3]); 
   COMBA_STORE(C->dp[2]);
   /* 3 */
   COMBA_FORWARD;
   MULADD(at[1], at[5]);    MULADD(at[2], at[4]); 
   COMBA_STORE(C->dp[3]);
   /* 4 */
   COMBA_FORWARD;
   MULADD(at[2], at[5]); 
   COMBA_STORE(C->dp[4]);
   COMBA_STORE2(C->dp[5]);
   C->used = 6;
   C->sign = A->sign ^ B->sign;
   fp_clamp(C);
   COMBA_FINI;

   return FP_OKAY;
}
#endif
