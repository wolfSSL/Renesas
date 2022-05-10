/* x509_vfy.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* x509_vfy.h for openSSL */

#ifndef WOLFSSL_x509_vfy_H_
#define WOLFSSL_x509_vfy_H_

#include <wolfssl/openssl/x509v3.h>

#ifdef __cplusplus
    extern "C" {
#endif

#if defined(WOLFSSL_QT) || defined(OPENSSL_ALL)
    WOLFSSL_API int wolfSSL_X509_STORE_CTX_set_purpose(WOLFSSL_X509_STORE_CTX *ctx, int purpose);
    WOLFSSL_API void wolfSSL_X509_STORE_CTX_set_flags(WOLFSSL_X509_STORE_CTX *ctx,
        unsigned long flags);
#endif

#define X509_STORE_CTX_set_purpose  wolfSSL_X509_STORE_CTX_set_purpose
#define X509_STORE_CTX_set_flags    wolfSSL_X509_STORE_CTX_set_flags

#ifdef  __cplusplus
} /* extern "C" */
#endif

#endif /* WOLFSSL_x509_vfy_H_ */
