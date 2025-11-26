/* test_curve448.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_CURVE448_H
#define WOLFCRYPT_TEST_CURVE448_H

#include <tests/api/api_decl.h>

int test_wc_curve448_make_key(void);
int test_wc_curve448_shared_secret_ex(void);
int test_wc_curve448_export_public_ex(void);
int test_wc_curve448_export_private_raw_ex(void);
int test_wc_curve448_export_key_raw(void);
int test_wc_curve448_import_private_raw_ex(void);
int test_wc_curve448_import_private(void);
int test_wc_curve448_init(void);
int test_wc_curve448_size(void);
int test_wc_Curve448PrivateKeyToDer(void);

#define TEST_CURVE448_DECLS                                                 \
    TEST_DECL_GROUP("curve448", test_wc_curve448_make_key),                 \
    TEST_DECL_GROUP("curve448", test_wc_curve448_shared_secret_ex),         \
    TEST_DECL_GROUP("curve448", test_wc_curve448_export_public_ex),         \
    TEST_DECL_GROUP("curve448", test_wc_curve448_export_private_raw_ex),    \
    TEST_DECL_GROUP("curve448", test_wc_curve448_export_key_raw),           \
    TEST_DECL_GROUP("curve448", test_wc_curve448_import_private_raw_ex),    \
    TEST_DECL_GROUP("curve448", test_wc_curve448_import_private),           \
    TEST_DECL_GROUP("curve448", test_wc_curve448_init),                     \
    TEST_DECL_GROUP("curve448", test_wc_curve448_size),                     \
    TEST_DECL_GROUP("curve448", test_wc_Curve448PrivateKeyToDer)

#endif /* WOLFCRYPT_TEST_CURVE448_H */
