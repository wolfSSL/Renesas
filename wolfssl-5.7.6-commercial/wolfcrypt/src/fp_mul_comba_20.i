/* fp_mul_comba_20.i
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifdef TFM_MUL20
int fp_mul_comba20(fp_int *A, fp_int *B, fp_int *C)
{
   fp_digit c0, c1, c2;
#ifndef WOLFSSL_SMALL_STACK
   fp_digit at[40];
#else
   fp_digit *at;
#endif

#ifdef WOLFSSL_SMALL_STACK
   at = (fp_digit*)XMALLOC(sizeof(fp_digit) * 40, NULL, DYNAMIC_TYPE_TMP_BUFFER);
   if (at == NULL)
       return FP_MEM;
#endif

   XMEMCPY(at, A->dp, 20 * sizeof(fp_digit));
   XMEMCPY(at+20, B->dp, 20 * sizeof(fp_digit));
   COMBA_START;

   COMBA_CLEAR;
   /* 0 */
   MULADD(at[0], at[20]); 
   COMBA_STORE(C->dp[0]);
   /* 1 */
   COMBA_FORWARD;
   MULADD(at[0], at[21]);    MULADD(at[1], at[20]); 
   COMBA_STORE(C->dp[1]);
   /* 2 */
   COMBA_FORWARD;
   MULADD(at[0], at[22]);    MULADD(at[1], at[21]);    MULADD(at[2], at[20]); 
   COMBA_STORE(C->dp[2]);
   /* 3 */
   COMBA_FORWARD;
   MULADD(at[0], at[23]);    MULADD(at[1], at[22]);    MULADD(at[2], at[21]);    MULADD(at[3], at[20]); 
   COMBA_STORE(C->dp[3]);
   /* 4 */
   COMBA_FORWARD;
   MULADD(at[0], at[24]);    MULADD(at[1], at[23]);    MULADD(at[2], at[22]);    MULADD(at[3], at[21]);    MULADD(at[4], at[20]); 
   COMBA_STORE(C->dp[4]);
   /* 5 */
   COMBA_FORWARD;
   MULADD(at[0], at[25]);    MULADD(at[1], at[24]);    MULADD(at[2], at[23]);    MULADD(at[3], at[22]);    MULADD(at[4], at[21]);    MULADD(at[5], at[20]); 
   COMBA_STORE(C->dp[5]);
   /* 6 */
   COMBA_FORWARD;
   MULADD(at[0], at[26]);    MULADD(at[1], at[25]);    MULADD(at[2], at[24]);    MULADD(at[3], at[23]);    MULADD(at[4], at[22]);    MULADD(at[5], at[21]);    MULADD(at[6], at[20]); 
   COMBA_STORE(C->dp[6]);
   /* 7 */
   COMBA_FORWARD;
   MULADD(at[0], at[27]);    MULADD(at[1], at[26]);    MULADD(at[2], at[25]);    MULADD(at[3], at[24]);    MULADD(at[4], at[23]);    MULADD(at[5], at[22]);    MULADD(at[6], at[21]);    MULADD(at[7], at[20]); 
   COMBA_STORE(C->dp[7]);
   /* 8 */
   COMBA_FORWARD;
   MULADD(at[0], at[28]);    MULADD(at[1], at[27]);    MULADD(at[2], at[26]);    MULADD(at[3], at[25]);    MULADD(at[4], at[24]);    MULADD(at[5], at[23]);    MULADD(at[6], at[22]);    MULADD(at[7], at[21]);    MULADD(at[8], at[20]); 
   COMBA_STORE(C->dp[8]);
   /* 9 */
   COMBA_FORWARD;
   MULADD(at[0], at[29]);    MULADD(at[1], at[28]);    MULADD(at[2], at[27]);    MULADD(at[3], at[26]);    MULADD(at[4], at[25]);    MULADD(at[5], at[24]);    MULADD(at[6], at[23]);    MULADD(at[7], at[22]);    MULADD(at[8], at[21]);    MULADD(at[9], at[20]); 
   COMBA_STORE(C->dp[9]);
   /* 10 */
   COMBA_FORWARD;
   MULADD(at[0], at[30]);    MULADD(at[1], at[29]);    MULADD(at[2], at[28]);    MULADD(at[3], at[27]);    MULADD(at[4], at[26]);    MULADD(at[5], at[25]);    MULADD(at[6], at[24]);    MULADD(at[7], at[23]);    MULADD(at[8], at[22]);    MULADD(at[9], at[21]);    MULADD(at[10], at[20]); 
   COMBA_STORE(C->dp[10]);
   /* 11 */
   COMBA_FORWARD;
   MULADD(at[0], at[31]);    MULADD(at[1], at[30]);    MULADD(at[2], at[29]);    MULADD(at[3], at[28]);    MULADD(at[4], at[27]);    MULADD(at[5], at[26]);    MULADD(at[6], at[25]);    MULADD(at[7], at[24]);    MULADD(at[8], at[23]);    MULADD(at[9], at[22]);    MULADD(at[10], at[21]);    MULADD(at[11], at[20]); 
   COMBA_STORE(C->dp[11]);
   /* 12 */
   COMBA_FORWARD;
   MULADD(at[0], at[32]);    MULADD(at[1], at[31]);    MULADD(at[2], at[30]);    MULADD(at[3], at[29]);    MULADD(at[4], at[28]);    MULADD(at[5], at[27]);    MULADD(at[6], at[26]);    MULADD(at[7], at[25]);    MULADD(at[8], at[24]);    MULADD(at[9], at[23]);    MULADD(at[10], at[22]);    MULADD(at[11], at[21]);    MULADD(at[12], at[20]); 
   COMBA_STORE(C->dp[12]);
   /* 13 */
   COMBA_FORWARD;
   MULADD(at[0], at[33]);    MULADD(at[1], at[32]);    MULADD(at[2], at[31]);    MULADD(at[3], at[30]);    MULADD(at[4], at[29]);    MULADD(at[5], at[28]);    MULADD(at[6], at[27]);    MULADD(at[7], at[26]);    MULADD(at[8], at[25]);    MULADD(at[9], at[24]);    MULADD(at[10], at[23]);    MULADD(at[11], at[22]);    MULADD(at[12], at[21]);    MULADD(at[13], at[20]); 
   COMBA_STORE(C->dp[13]);
   /* 14 */
   COMBA_FORWARD;
   MULADD(at[0], at[34]);    MULADD(at[1], at[33]);    MULADD(at[2], at[32]);    MULADD(at[3], at[31]);    MULADD(at[4], at[30]);    MULADD(at[5], at[29]);    MULADD(at[6], at[28]);    MULADD(at[7], at[27]);    MULADD(at[8], at[26]);    MULADD(at[9], at[25]);    MULADD(at[10], at[24]);    MULADD(at[11], at[23]);    MULADD(at[12], at[22]);    MULADD(at[13], at[21]);    MULADD(at[14], at[20]); 
   COMBA_STORE(C->dp[14]);
   /* 15 */
   COMBA_FORWARD;
   MULADD(at[0], at[35]);    MULADD(at[1], at[34]);    MULADD(at[2], at[33]);    MULADD(at[3], at[32]);    MULADD(at[4], at[31]);    MULADD(at[5], at[30]);    MULADD(at[6], at[29]);    MULADD(at[7], at[28]);    MULADD(at[8], at[27]);    MULADD(at[9], at[26]);    MULADD(at[10], at[25]);    MULADD(at[11], at[24]);    MULADD(at[12], at[23]);    MULADD(at[13], at[22]);    MULADD(at[14], at[21]);    MULADD(at[15], at[20]); 
   COMBA_STORE(C->dp[15]);
   /* 16 */
   COMBA_FORWARD;
   MULADD(at[0], at[36]);    MULADD(at[1], at[35]);    MULADD(at[2], at[34]);    MULADD(at[3], at[33]);    MULADD(at[4], at[32]);    MULADD(at[5], at[31]);    MULADD(at[6], at[30]);    MULADD(at[7], at[29]);    MULADD(at[8], at[28]);    MULADD(at[9], at[27]);    MULADD(at[10], at[26]);    MULADD(at[11], at[25]);    MULADD(at[12], at[24]);    MULADD(at[13], at[23]);    MULADD(at[14], at[22]);    MULADD(at[15], at[21]);    MULADD(at[16], at[20]); 
   COMBA_STORE(C->dp[16]);
   /* 17 */
   COMBA_FORWARD;
   MULADD(at[0], at[37]);    MULADD(at[1], at[36]);    MULADD(at[2], at[35]);    MULADD(at[3], at[34]);    MULADD(at[4], at[33]);    MULADD(at[5], at[32]);    MULADD(at[6], at[31]);    MULADD(at[7], at[30]);    MULADD(at[8], at[29]);    MULADD(at[9], at[28]);    MULADD(at[10], at[27]);    MULADD(at[11], at[26]);    MULADD(at[12], at[25]);    MULADD(at[13], at[24]);    MULADD(at[14], at[23]);    MULADD(at[15], at[22]);    MULADD(at[16], at[21]);    MULADD(at[17], at[20]); 
   COMBA_STORE(C->dp[17]);
   /* 18 */
   COMBA_FORWARD;
   MULADD(at[0], at[38]);    MULADD(at[1], at[37]);    MULADD(at[2], at[36]);    MULADD(at[3], at[35]);    MULADD(at[4], at[34]);    MULADD(at[5], at[33]);    MULADD(at[6], at[32]);    MULADD(at[7], at[31]);    MULADD(at[8], at[30]);    MULADD(at[9], at[29]);    MULADD(at[10], at[28]);    MULADD(at[11], at[27]);    MULADD(at[12], at[26]);    MULADD(at[13], at[25]);    MULADD(at[14], at[24]);    MULADD(at[15], at[23]);    MULADD(at[16], at[22]);    MULADD(at[17], at[21]);    MULADD(at[18], at[20]); 
   COMBA_STORE(C->dp[18]);
   /* 19 */
   COMBA_FORWARD;
   MULADD(at[0], at[39]);    MULADD(at[1], at[38]);    MULADD(at[2], at[37]);    MULADD(at[3], at[36]);    MULADD(at[4], at[35]);    MULADD(at[5], at[34]);    MULADD(at[6], at[33]);    MULADD(at[7], at[32]);    MULADD(at[8], at[31]);    MULADD(at[9], at[30]);    MULADD(at[10], at[29]);    MULADD(at[11], at[28]);    MULADD(at[12], at[27]);    MULADD(at[13], at[26]);    MULADD(at[14], at[25]);    MULADD(at[15], at[24]);    MULADD(at[16], at[23]);    MULADD(at[17], at[22]);    MULADD(at[18], at[21]);    MULADD(at[19], at[20]); 
   COMBA_STORE(C->dp[19]);
   /* 20 */
   COMBA_FORWARD;
   MULADD(at[1], at[39]);    MULADD(at[2], at[38]);    MULADD(at[3], at[37]);    MULADD(at[4], at[36]);    MULADD(at[5], at[35]);    MULADD(at[6], at[34]);    MULADD(at[7], at[33]);    MULADD(at[8], at[32]);    MULADD(at[9], at[31]);    MULADD(at[10], at[30]);    MULADD(at[11], at[29]);    MULADD(at[12], at[28]);    MULADD(at[13], at[27]);    MULADD(at[14], at[26]);    MULADD(at[15], at[25]);    MULADD(at[16], at[24]);    MULADD(at[17], at[23]);    MULADD(at[18], at[22]);    MULADD(at[19], at[21]); 
   COMBA_STORE(C->dp[20]);
   /* 21 */
   COMBA_FORWARD;
   MULADD(at[2], at[39]);    MULADD(at[3], at[38]);    MULADD(at[4], at[37]);    MULADD(at[5], at[36]);    MULADD(at[6], at[35]);    MULADD(at[7], at[34]);    MULADD(at[8], at[33]);    MULADD(at[9], at[32]);    MULADD(at[10], at[31]);    MULADD(at[11], at[30]);    MULADD(at[12], at[29]);    MULADD(at[13], at[28]);    MULADD(at[14], at[27]);    MULADD(at[15], at[26]);    MULADD(at[16], at[25]);    MULADD(at[17], at[24]);    MULADD(at[18], at[23]);    MULADD(at[19], at[22]); 
   COMBA_STORE(C->dp[21]);
   /* 22 */
   COMBA_FORWARD;
   MULADD(at[3], at[39]);    MULADD(at[4], at[38]);    MULADD(at[5], at[37]);    MULADD(at[6], at[36]);    MULADD(at[7], at[35]);    MULADD(at[8], at[34]);    MULADD(at[9], at[33]);    MULADD(at[10], at[32]);    MULADD(at[11], at[31]);    MULADD(at[12], at[30]);    MULADD(at[13], at[29]);    MULADD(at[14], at[28]);    MULADD(at[15], at[27]);    MULADD(at[16], at[26]);    MULADD(at[17], at[25]);    MULADD(at[18], at[24]);    MULADD(at[19], at[23]); 
   COMBA_STORE(C->dp[22]);
   /* 23 */
   COMBA_FORWARD;
   MULADD(at[4], at[39]);    MULADD(at[5], at[38]);    MULADD(at[6], at[37]);    MULADD(at[7], at[36]);    MULADD(at[8], at[35]);    MULADD(at[9], at[34]);    MULADD(at[10], at[33]);    MULADD(at[11], at[32]);    MULADD(at[12], at[31]);    MULADD(at[13], at[30]);    MULADD(at[14], at[29]);    MULADD(at[15], at[28]);    MULADD(at[16], at[27]);    MULADD(at[17], at[26]);    MULADD(at[18], at[25]);    MULADD(at[19], at[24]); 
   COMBA_STORE(C->dp[23]);
   /* 24 */
   COMBA_FORWARD;
   MULADD(at[5], at[39]);    MULADD(at[6], at[38]);    MULADD(at[7], at[37]);    MULADD(at[8], at[36]);    MULADD(at[9], at[35]);    MULADD(at[10], at[34]);    MULADD(at[11], at[33]);    MULADD(at[12], at[32]);    MULADD(at[13], at[31]);    MULADD(at[14], at[30]);    MULADD(at[15], at[29]);    MULADD(at[16], at[28]);    MULADD(at[17], at[27]);    MULADD(at[18], at[26]);    MULADD(at[19], at[25]); 
   COMBA_STORE(C->dp[24]);
   /* 25 */
   COMBA_FORWARD;
   MULADD(at[6], at[39]);    MULADD(at[7], at[38]);    MULADD(at[8], at[37]);    MULADD(at[9], at[36]);    MULADD(at[10], at[35]);    MULADD(at[11], at[34]);    MULADD(at[12], at[33]);    MULADD(at[13], at[32]);    MULADD(at[14], at[31]);    MULADD(at[15], at[30]);    MULADD(at[16], at[29]);    MULADD(at[17], at[28]);    MULADD(at[18], at[27]);    MULADD(at[19], at[26]); 
   COMBA_STORE(C->dp[25]);
   /* 26 */
   COMBA_FORWARD;
   MULADD(at[7], at[39]);    MULADD(at[8], at[38]);    MULADD(at[9], at[37]);    MULADD(at[10], at[36]);    MULADD(at[11], at[35]);    MULADD(at[12], at[34]);    MULADD(at[13], at[33]);    MULADD(at[14], at[32]);    MULADD(at[15], at[31]);    MULADD(at[16], at[30]);    MULADD(at[17], at[29]);    MULADD(at[18], at[28]);    MULADD(at[19], at[27]); 
   COMBA_STORE(C->dp[26]);
   /* 27 */
   COMBA_FORWARD;
   MULADD(at[8], at[39]);    MULADD(at[9], at[38]);    MULADD(at[10], at[37]);    MULADD(at[11], at[36]);    MULADD(at[12], at[35]);    MULADD(at[13], at[34]);    MULADD(at[14], at[33]);    MULADD(at[15], at[32]);    MULADD(at[16], at[31]);    MULADD(at[17], at[30]);    MULADD(at[18], at[29]);    MULADD(at[19], at[28]); 
   COMBA_STORE(C->dp[27]);
   /* 28 */
   COMBA_FORWARD;
   MULADD(at[9], at[39]);    MULADD(at[10], at[38]);    MULADD(at[11], at[37]);    MULADD(at[12], at[36]);    MULADD(at[13], at[35]);    MULADD(at[14], at[34]);    MULADD(at[15], at[33]);    MULADD(at[16], at[32]);    MULADD(at[17], at[31]);    MULADD(at[18], at[30]);    MULADD(at[19], at[29]); 
   COMBA_STORE(C->dp[28]);
   /* 29 */
   COMBA_FORWARD;
   MULADD(at[10], at[39]);    MULADD(at[11], at[38]);    MULADD(at[12], at[37]);    MULADD(at[13], at[36]);    MULADD(at[14], at[35]);    MULADD(at[15], at[34]);    MULADD(at[16], at[33]);    MULADD(at[17], at[32]);    MULADD(at[18], at[31]);    MULADD(at[19], at[30]); 
   COMBA_STORE(C->dp[29]);
   /* 30 */
   COMBA_FORWARD;
   MULADD(at[11], at[39]);    MULADD(at[12], at[38]);    MULADD(at[13], at[37]);    MULADD(at[14], at[36]);    MULADD(at[15], at[35]);    MULADD(at[16], at[34]);    MULADD(at[17], at[33]);    MULADD(at[18], at[32]);    MULADD(at[19], at[31]); 
   COMBA_STORE(C->dp[30]);
   /* 31 */
   COMBA_FORWARD;
   MULADD(at[12], at[39]);    MULADD(at[13], at[38]);    MULADD(at[14], at[37]);    MULADD(at[15], at[36]);    MULADD(at[16], at[35]);    MULADD(at[17], at[34]);    MULADD(at[18], at[33]);    MULADD(at[19], at[32]); 
   COMBA_STORE(C->dp[31]);
   /* 32 */
   COMBA_FORWARD;
   MULADD(at[13], at[39]);    MULADD(at[14], at[38]);    MULADD(at[15], at[37]);    MULADD(at[16], at[36]);    MULADD(at[17], at[35]);    MULADD(at[18], at[34]);    MULADD(at[19], at[33]); 
   COMBA_STORE(C->dp[32]);
   /* 33 */
   COMBA_FORWARD;
   MULADD(at[14], at[39]);    MULADD(at[15], at[38]);    MULADD(at[16], at[37]);    MULADD(at[17], at[36]);    MULADD(at[18], at[35]);    MULADD(at[19], at[34]); 
   COMBA_STORE(C->dp[33]);
   /* 34 */
   COMBA_FORWARD;
   MULADD(at[15], at[39]);    MULADD(at[16], at[38]);    MULADD(at[17], at[37]);    MULADD(at[18], at[36]);    MULADD(at[19], at[35]); 
   COMBA_STORE(C->dp[34]);
   /* 35 */
   COMBA_FORWARD;
   MULADD(at[16], at[39]);    MULADD(at[17], at[38]);    MULADD(at[18], at[37]);    MULADD(at[19], at[36]); 
   COMBA_STORE(C->dp[35]);
   /* 36 */
   COMBA_FORWARD;
   MULADD(at[17], at[39]);    MULADD(at[18], at[38]);    MULADD(at[19], at[37]); 
   COMBA_STORE(C->dp[36]);
   /* 37 */
   COMBA_FORWARD;
   MULADD(at[18], at[39]);    MULADD(at[19], at[38]); 
   COMBA_STORE(C->dp[37]);
   /* 38 */
   COMBA_FORWARD;
   MULADD(at[19], at[39]); 
   COMBA_STORE(C->dp[38]);
   COMBA_STORE2(C->dp[39]);
   C->used = 40;
   C->sign = A->sign ^ B->sign;
   fp_clamp(C);
   COMBA_FINI;

#ifdef WOLFSSL_SMALL_STACK
   XFREE(at, NULL, DYNAMIC_TYPE_TMP_BUFFER);
#endif
   return FP_OKAY;
}
#endif
