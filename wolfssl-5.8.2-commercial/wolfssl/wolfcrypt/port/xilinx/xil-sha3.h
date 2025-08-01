/* xil-sha3.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLF_XIL_CRYPT_SHA3_H
#define WOLF_XIL_CRYPT_SHA3_H

#if defined(WOLFSSL_SHA3) && defined(WOLFSSL_XILINX_CRYPT)
#ifdef WOLFSSL_XILINX_CRYPT_VERSAL
#include <wolfssl/wolfcrypt/port/xilinx/xil-versal-glue.h>
#else
#include <xsecure_sha.h>
#endif

#ifdef __cplusplus
    extern "C" {
#endif

/* Sha3 digest */
typedef struct wc_Sha3 {
#ifdef WOLFSSL_XILINX_CRYPT_VERSAL
    wc_Xsecure xSec;
#else
    XSecure_Sha3 hw;
    XCsuDma      dma;
#endif
} wc_Sha3;

#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* WOLFSSL_SHA3 && WOLFSSL_XILINX_CRYPT */
#endif /* WOLF_XIL_CRYPT_SHA3_H */

