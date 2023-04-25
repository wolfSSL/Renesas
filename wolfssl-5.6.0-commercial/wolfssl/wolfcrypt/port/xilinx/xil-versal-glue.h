/* xil-versal-glue.h
 *
 * Copyright (C) 2006-2023 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLF_XIL_CRYPT_VERSAL_GLUE_H
#define WOLF_XIL_CRYPT_VERSAL_GLUE_H

#include <wolfssl/wolfcrypt/settings.h>

#ifdef WOLFSSL_XILINX_CRYPT_VERSAL
#include <xil_types.h>
#include <xsecure_mailbox.h>
#include <xsecure_defs.h>

#ifdef __cplusplus
extern "C" {
#endif

#define XIL_CAST_U64(v) ((u64)(UINTPTR)(v))

#ifdef XSECURE_CACHE_DISABLE
#define WOLFSSL_XIL_DCACHE_INVALIDATE_RANGE(p, l) do{}while(0)
#define WOLFSSL_XIL_DCACHE_FLUSH_RANGE(p, l)      do{}while(0)
#else
#define WOLFSSL_XIL_DCACHE_INVALIDATE_RANGE(p, l) \
    do{ Xil_DCacheInvalidateRange((p), (l)); }while(0)
#define WOLFSSL_XIL_DCACHE_FLUSH_RANGE(p, l) \
    do{ Xil_DCacheFlushRange((p), (l)); }while(0)
#endif

#if defined(DEBUG_WOLFSSL) && !defined(WOLFSSL_DEBUG_ERRORS_ONLY) \
    && !defined(WOLFSSL_XIL_MSG_NO_SLEEP)
#include <unistd.h>
#define WOLFSSL_XIL_SLEEP(n) do{ sleep(n); }while(0)
#else
#define WOLFSSL_XIL_SLEEP(n) do{}while(0)
#endif

/* Provide our own message macro since the Versal PLM maybe
 * prints an error message to the same console.
 * In order to not mix those outputs up, sleep a little while
 * before printing our message.
 * This behavior can be disabled by defining `WOLFSSL_XIL_MSG_NO_SLEEP`
 */
#define WOLFSSL_XIL_MSG(msg) do { \
    WOLFSSL_XIL_SLEEP(1); \
    WOLFSSL_MSG(msg); \
} while(0)
#define WOLFSSL_XIL_ERROR(msg, err) do { \
    WOLFSSL_XIL_MSG(msg); \
    WOLFSSL_MSG_EX("Xilinx API returned 0x%08x: %s", (err), \
                           wc_XsecureErrorToString(err)); \
} while(0)



#define WOLFSSL_XSECURE_QWORD_SIZE      16u
#define WOLFSSL_XSECURE_AES_KEY_SIZE    32u
#define WOLFSSL_XSECURE_AES_IV_SIZE     12u
#define WOLFSSL_XSECURE_RSA_KEY_SIZE    512u

enum {
    WOLFSSL_XSECURE_ECC_NIST_P384 = 4,
    WOLFSSL_XSECURE_ECC_NIST_P521 = 5,
    WOLFSSL_XSECURE_ECC_NUM
};

typedef struct Xsecure {
    ALIGN64 u8 mem[XSECURE_SHARED_MEM_SIZE];
    XMailbox mb;
    XSecure_ClientInstance cinst;
} wc_Xsecure;

WOLFSSL_LOCAL int wc_InitXsecure(wc_Xsecure* xsec);
WOLFSSL_LOCAL const char *wc_XsecureErrorToString(int err);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* WOLFSSL_XILINX_CRYPT_VERSAL */
#endif /* WOLF_XIL_CRYPT_VERSAL_GLUE_H */

