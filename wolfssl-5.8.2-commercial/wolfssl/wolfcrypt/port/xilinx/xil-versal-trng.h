/* xil-versal-trng.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLF_XIL_CRYPT_VERSAL_TRNG_H
#define WOLF_XIL_CRYPT_VERSAL_TRNG_H

#include <wolfssl/wolfcrypt/settings.h>

#ifdef WOLFSSL_XILINX_CRYPT_VERSAL

#ifdef __cplusplus
extern "C" {
#endif
WOLFSSL_LOCAL int wc_VersalTrngInit(byte* nonce, word32 nonceSz);
WOLFSSL_LOCAL int wc_VersalTrngReset(void);
WOLFSSL_LOCAL int wc_VersalTrngSelftest(void);
WOLFSSL_LOCAL int wc_VersalTrngGenerate(byte *output, word32 sz);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* versal */
#endif /* WOLF_XIL_CRYPT_VERSAL_TRNG_H */

