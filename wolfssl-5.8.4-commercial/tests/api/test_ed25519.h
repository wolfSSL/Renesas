/* test_ed25519.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_ED25519_H
#define WOLFCRYPT_TEST_ED25519_H

#include <tests/api/api_decl.h>

int test_wc_ed25519_make_key(void);
int test_wc_ed25519_init(void);
int test_wc_ed25519_sign_msg(void);
int test_wc_ed25519_import_public(void);
int test_wc_ed25519_import_private_key(void);
int test_wc_ed25519_export(void);
int test_wc_ed25519_size(void);
int test_wc_ed25519_exportKey(void);
int test_wc_Ed25519PublicKeyToDer(void);
int test_wc_Ed25519KeyToDer(void);
int test_wc_Ed25519PrivateKeyToDer(void);

#define TEST_ED25519_DECLS                                          \
    TEST_DECL_GROUP("ed25519", test_wc_ed25519_make_key),           \
    TEST_DECL_GROUP("ed25519", test_wc_ed25519_init),               \
    TEST_DECL_GROUP("ed25519", test_wc_ed25519_sign_msg),           \
    TEST_DECL_GROUP("ed25519", test_wc_ed25519_import_public),      \
    TEST_DECL_GROUP("ed25519", test_wc_ed25519_import_private_key), \
    TEST_DECL_GROUP("ed25519", test_wc_ed25519_export),             \
    TEST_DECL_GROUP("ed25519", test_wc_ed25519_size),               \
    TEST_DECL_GROUP("ed25519", test_wc_ed25519_exportKey),          \
    TEST_DECL_GROUP("ed25519", test_wc_Ed25519PublicKeyToDer),      \
    TEST_DECL_GROUP("ed25519", test_wc_Ed25519KeyToDer),            \
    TEST_DECL_GROUP("ed25519", test_wc_Ed25519PrivateKeyToDer)

#endif /* WOLFCRYPT_TEST_ED25519_H */
