/* test_ed448.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_ED448_H
#define WOLFCRYPT_TEST_ED448_H

#include <tests/api/api_decl.h>

int test_wc_ed448_make_key(void);
int test_wc_ed448_init(void);
int test_wc_ed448_sign_msg(void);
int test_wc_ed448_import_public(void);
int test_wc_ed448_import_private_key(void);
int test_wc_ed448_export(void);
int test_wc_ed448_size(void);
int test_wc_ed448_exportKey(void);
int test_wc_Ed448PublicKeyToDer(void);
int test_wc_Ed448KeyToDer(void);
int test_wc_Ed448PrivateKeyToDer(void);

#define TEST_ED448_DECLS                                          \
    TEST_DECL_GROUP("ed448", test_wc_ed448_make_key),             \
    TEST_DECL_GROUP("ed448", test_wc_ed448_init),                 \
    TEST_DECL_GROUP("ed448", test_wc_ed448_sign_msg),             \
    TEST_DECL_GROUP("ed448", test_wc_ed448_import_public),        \
    TEST_DECL_GROUP("ed448", test_wc_ed448_import_private_key),   \
    TEST_DECL_GROUP("ed448", test_wc_ed448_export),               \
    TEST_DECL_GROUP("ed448", test_wc_ed448_size),                 \
    TEST_DECL_GROUP("ed448", test_wc_ed448_exportKey),            \
    TEST_DECL_GROUP("ed448", test_wc_Ed448PublicKeyToDer),        \
    TEST_DECL_GROUP("ed448", test_wc_Ed448KeyToDer),              \
    TEST_DECL_GROUP("ed448", test_wc_Ed448PrivateKeyToDer)

#endif /* WOLFCRYPT_TEST_ED448_H */
