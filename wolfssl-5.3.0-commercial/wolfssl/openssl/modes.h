/* modes.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
#ifndef WOLFSSL_OPENSSL_MODES_H
#define WOLFSSL_OPENSSL_MODES_H

#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/openssl/ssl.h>

typedef void (*WOLFSSL_CBC128_CB) (const unsigned char *in,
        unsigned char *out, size_t len, const void *key,
        unsigned char *iv, int enc);

WOLFSSL_API size_t wolfSSL_CRYPTO_cts128_encrypt(const unsigned char *in,
        unsigned char *out, size_t len, const void *key,
        unsigned char *iv, WOLFSSL_CBC128_CB cbc);
WOLFSSL_API size_t wolfSSL_CRYPTO_cts128_decrypt(const unsigned char *in,
        unsigned char *out, size_t len, const void *key,
        unsigned char *iv, WOLFSSL_CBC128_CB cbc);

#define WOLFSSL_CTS128_BLOCK_SZ         16

/* Compatibility layer defines */
#define CRYPTO_cts128_encrypt           wolfSSL_CRYPTO_cts128_encrypt
#define CRYPTO_cts128_decrypt           wolfSSL_CRYPTO_cts128_decrypt
#define cbc128_f                        WOLFSSL_CBC128_CB

#endif /* WOLFSSL_OPENSSL_MODES_H */
