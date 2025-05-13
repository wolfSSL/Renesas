/* test_aes.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_AES_H
#define WOLFCRYPT_TEST_AES_H

#include <tests/api/api_decl.h>

int test_wc_AesSetKey(void);
int test_wc_AesSetIV(void);
int test_wc_AesCbcEncryptDecrypt(void);
int test_wc_AesCtsEncryptDecrypt(void);
int test_wc_AesCtrEncryptDecrypt(void);
int test_wc_AesGcmSetKey(void);
int test_wc_AesGcmEncryptDecrypt(void);
int test_wc_AesGcmMixedEncDecLongIV(void);
int test_wc_AesGcmStream(void);
int test_wc_AesCcmSetKey(void);
int test_wc_AesCcmEncryptDecrypt(void);
#if defined(WOLFSSL_AES_EAX) && \
    (!defined(HAVE_FIPS) || FIPS_VERSION_GE(5, 3)) && !defined(HAVE_SELFTEST)
int test_wc_AesEaxVectors(void);
int test_wc_AesEaxEncryptAuth(void);
int test_wc_AesEaxDecryptAuth(void);
#endif /* WOLFSSL_AES_EAX */

int test_wc_GmacSetKey(void);
int test_wc_GmacUpdate(void);

#define TEST_AES_DECLS                                          \
    TEST_DECL_GROUP("aes", test_wc_AesSetKey),                  \
    TEST_DECL_GROUP("aes", test_wc_AesSetIV),                   \
    TEST_DECL_GROUP("aes", test_wc_AesCbcEncryptDecrypt),       \
    TEST_DECL_GROUP("aes", test_wc_AesCtsEncryptDecrypt),       \
    TEST_DECL_GROUP("aes", test_wc_AesCtrEncryptDecrypt),       \
    TEST_DECL_GROUP("aes", test_wc_AesGcmSetKey),               \
    TEST_DECL_GROUP("aes", test_wc_AesGcmEncryptDecrypt),       \
    TEST_DECL_GROUP("aes", test_wc_AesGcmMixedEncDecLongIV),    \
    TEST_DECL_GROUP("aes", test_wc_AesGcmStream),               \
    TEST_DECL_GROUP("aes", test_wc_AesCcmSetKey),               \
    TEST_DECL_GROUP("aes", test_wc_AesCcmEncryptDecrypt)

#if defined(WOLFSSL_AES_EAX) && \
    (!defined(HAVE_FIPS) || FIPS_VERSION_GE(5, 3)) && !defined(HAVE_SELFTEST)
#define TEST_AES_EAX_DECLS                                  \
    TEST_DECL_GROUP("aes-eax", test_wc_AesEaxVectors),      \
    TEST_DECL_GROUP("aes-eax", test_wc_AesEaxEncryptAuth),  \
    TEST_DECL_GROUP("aes-eax", test_wc_AesEaxDecryptAuth)
#endif /* WOLFSSL_AES_EAX */

#define TEST_GMAC_DECLS                             \
    TEST_DECL_GROUP("gmac", test_wc_GmacSetKey),    \
    TEST_DECL_GROUP("gmac", test_wc_GmacUpdate)

#endif /* WOLFCRYPT_TEST_AES_H */
