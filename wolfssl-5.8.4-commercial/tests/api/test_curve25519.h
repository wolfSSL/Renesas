/* test_curve25519.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_CURVE25519_H
#define WOLFCRYPT_TEST_CURVE25519_H

#include <tests/api/api_decl.h>

int test_wc_curve25519_init(void);
int test_wc_curve25519_size(void);
int test_wc_curve25519_export_key_raw(void);
int test_wc_curve25519_export_key_raw_ex(void);
int test_wc_curve25519_make_key(void);
int test_wc_curve25519_shared_secret_ex(void);
int test_wc_curve25519_make_pub(void);
int test_wc_curve25519_export_public_ex(void);
int test_wc_curve25519_export_private_raw_ex(void);
int test_wc_curve25519_import_private_raw_ex(void);
int test_wc_curve25519_import_private(void);

#define TEST_CURVE25519_DECLS                                                  \
    TEST_DECL_GROUP("curve25519", test_wc_curve25519_init),                    \
    TEST_DECL_GROUP("curve25519", test_wc_curve25519_size),                    \
    TEST_DECL_GROUP("curve25519", test_wc_curve25519_export_key_raw),          \
    TEST_DECL_GROUP("curve25519", test_wc_curve25519_export_key_raw_ex),       \
    TEST_DECL_GROUP("curve25519", test_wc_curve25519_make_key),                \
    TEST_DECL_GROUP("curve25519", test_wc_curve25519_shared_secret_ex),        \
    TEST_DECL_GROUP("curve25519", test_wc_curve25519_make_pub),                \
    TEST_DECL_GROUP("curve25519", test_wc_curve25519_export_public_ex),        \
    TEST_DECL_GROUP("curve25519", test_wc_curve25519_export_private_raw_ex),   \
    TEST_DECL_GROUP("curve25519", test_wc_curve25519_import_private_raw_ex),   \
    TEST_DECL_GROUP("curve25519", test_wc_curve25519_import_private)

#endif /* WOLFCRYPT_TEST_CURVE25519_H */
