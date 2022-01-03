/* fp_sqr_comba_3.i
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifdef TFM_SQR3
int fp_sqr_comba3(fp_int *A, fp_int *B)
{
   fp_digit *a, b[6], c0, c1, c2;
#ifdef TFM_ISO
   fp_word tt;
#endif

   a = A->dp;
   COMBA_START; 

   /* clear carries */
   CLEAR_CARRY;

   /* output 0 */
   SQRADD(a[0],a[0]);
   COMBA_STORE(b[0]);

   /* output 1 */
   CARRY_FORWARD;
   SQRADD2(a[0], a[1]); 
   COMBA_STORE(b[1]);

   /* output 2 */
   CARRY_FORWARD;
   SQRADD2(a[0], a[2]); SQRADD(a[1], a[1]); 
   COMBA_STORE(b[2]);

   /* output 3 */
   CARRY_FORWARD;
   SQRADD2(a[1], a[2]); 
   COMBA_STORE(b[3]);

   /* output 4 */
   CARRY_FORWARD;
   SQRADD(a[2], a[2]); 
   COMBA_STORE(b[4]);
   COMBA_STORE2(b[5]);
   COMBA_FINI;

   B->used = 6;
   B->sign = FP_ZPOS;
   XMEMCPY(B->dp, b, 6 * sizeof(fp_digit));
   fp_clamp(B);

   return FP_OKAY;
}
#endif


