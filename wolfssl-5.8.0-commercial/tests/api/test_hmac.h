/* test_hmac.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_HMAC_H
#define WOLFCRYPT_TEST_HMAC_H

#include <tests/api/api_decl.h>

int test_wc_Md5HmacSetKey(void);
int test_wc_Md5HmacUpdate(void);
int test_wc_Md5HmacFinal(void);
int test_wc_ShaHmacSetKey(void);
int test_wc_ShaHmacUpdate(void);
int test_wc_ShaHmacFinal(void);
int test_wc_Sha224HmacSetKey(void);
int test_wc_Sha224HmacUpdate(void);
int test_wc_Sha224HmacFinal(void);
int test_wc_Sha256HmacSetKey(void);
int test_wc_Sha256HmacUpdate(void);
int test_wc_Sha256HmacFinal(void);
int test_wc_Sha384HmacSetKey(void);
int test_wc_Sha384HmacUpdate(void);
int test_wc_Sha384HmacFinal(void);

#define TEST_HMAC_DECLS                                 \
    TEST_DECL_GROUP("hmac", test_wc_Md5HmacSetKey),     \
    TEST_DECL_GROUP("hmac", test_wc_Md5HmacUpdate),     \
    TEST_DECL_GROUP("hmac", test_wc_Md5HmacFinal),      \
    TEST_DECL_GROUP("hmac", test_wc_ShaHmacSetKey),     \
    TEST_DECL_GROUP("hmac", test_wc_ShaHmacUpdate),     \
    TEST_DECL_GROUP("hmac", test_wc_ShaHmacFinal),      \
    TEST_DECL_GROUP("hmac", test_wc_Sha224HmacSetKey),  \
    TEST_DECL_GROUP("hmac", test_wc_Sha224HmacUpdate),  \
    TEST_DECL_GROUP("hmac", test_wc_Sha224HmacFinal),   \
    TEST_DECL_GROUP("hmac", test_wc_Sha256HmacSetKey),  \
    TEST_DECL_GROUP("hmac", test_wc_Sha256HmacUpdate),  \
    TEST_DECL_GROUP("hmac", test_wc_Sha256HmacFinal),   \
    TEST_DECL_GROUP("hmac", test_wc_Sha384HmacSetKey),  \
    TEST_DECL_GROUP("hmac", test_wc_Sha384HmacUpdate),  \
    TEST_DECL_GROUP("hmac", test_wc_Sha384HmacFinal)

#endif /* WOLFCRYPT_TEST_HMAC_H */
