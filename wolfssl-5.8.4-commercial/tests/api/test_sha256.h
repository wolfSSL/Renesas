/* test_sha256.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_SHA256_H
#define WOLFCRYPT_TEST_SHA256_H

#include <tests/api/api_decl.h>

int test_wc_InitSha256(void);
int test_wc_Sha256Update(void);
int test_wc_Sha256Final(void);
int test_wc_Sha256FinalRaw(void);
int test_wc_Sha256_KATs(void);
int test_wc_Sha256_other(void);
int test_wc_Sha256Copy(void);
int test_wc_Sha256GetHash(void);
int test_wc_Sha256Transform(void);
int test_wc_Sha256_Flags(void);

int test_wc_InitSha224(void);
int test_wc_Sha224Update(void);
int test_wc_Sha224Final(void);
int test_wc_Sha224_KATs(void);
int test_wc_Sha224_other(void);
int test_wc_Sha224Copy(void);
int test_wc_Sha224GetHash(void);
int test_wc_Sha224_Flags(void);

#define TEST_SHA256_DECLS                               \
    TEST_DECL_GROUP("sha256", test_wc_InitSha256),      \
    TEST_DECL_GROUP("sha256", test_wc_Sha256Update),    \
    TEST_DECL_GROUP("sha256", test_wc_Sha256Final),     \
    TEST_DECL_GROUP("sha256", test_wc_Sha256FinalRaw),  \
    TEST_DECL_GROUP("sha256", test_wc_Sha256_KATs),     \
    TEST_DECL_GROUP("sha256", test_wc_Sha256_other),    \
    TEST_DECL_GROUP("sha256", test_wc_Sha256Copy),      \
    TEST_DECL_GROUP("sha256", test_wc_Sha256GetHash),   \
    TEST_DECL_GROUP("sha256", test_wc_Sha256Transform), \
    TEST_DECL_GROUP("sha256", test_wc_Sha256_Flags)

#define TEST_SHA224_DECLS                               \
    TEST_DECL_GROUP("sha224", test_wc_InitSha224),      \
    TEST_DECL_GROUP("sha224", test_wc_Sha224Update),    \
    TEST_DECL_GROUP("sha224", test_wc_Sha224Final),     \
    TEST_DECL_GROUP("sha224", test_wc_Sha224_KATs),     \
    TEST_DECL_GROUP("sha224", test_wc_Sha224_other),    \
    TEST_DECL_GROUP("sha224", test_wc_Sha224Copy),      \
    TEST_DECL_GROUP("sha224", test_wc_Sha224GetHash),   \
    TEST_DECL_GROUP("sha224", test_wc_Sha224_Flags)

#endif /* WOLFCRYPT_TEST_SHA256_H */
