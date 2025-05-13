/* test_sha.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_SHA_H
#define WOLFCRYPT_TEST_SHA_H

#include <tests/api/api_decl.h>

int test_wc_InitSha(void);
int test_wc_ShaUpdate(void);
int test_wc_ShaFinal(void);
int test_wc_ShaFinalRaw(void);
int test_wc_Sha_KATs(void);
int test_wc_Sha_other(void);
int test_wc_ShaCopy(void);
int test_wc_ShaGetHash(void);
int test_wc_ShaTransform(void);
int test_wc_Sha_Flags(void);

#define TEST_SHA_DECLS                              \
    TEST_DECL_GROUP("sha", test_wc_InitSha),        \
    TEST_DECL_GROUP("sha", test_wc_ShaUpdate),      \
    TEST_DECL_GROUP("sha", test_wc_ShaFinal),       \
    TEST_DECL_GROUP("sha", test_wc_ShaFinalRaw),    \
    TEST_DECL_GROUP("sha", test_wc_Sha_KATs),       \
    TEST_DECL_GROUP("sha", test_wc_Sha_other),      \
    TEST_DECL_GROUP("sha", test_wc_ShaCopy),        \
    TEST_DECL_GROUP("sha", test_wc_ShaGetHash),     \
    TEST_DECL_GROUP("sha", test_wc_ShaTransform),   \
    TEST_DECL_GROUP("sha", test_wc_Sha_Flags)

#endif /* WOLFCRYPT_TEST_SHA_H */
