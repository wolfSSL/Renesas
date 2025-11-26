/* test_tls13.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_TLS13_H
#define WOLFCRYPT_TEST_TLS13_H

#include <tests/api/api_decl.h>

int test_tls13_apis(void);
int test_tls13_cipher_suites(void);
int test_tls13_bad_psk_binder(void);
int test_tls13_rpk_handshake(void);
int test_tls13_pq_groups(void);
int test_tls13_early_data(void);
int test_tls13_same_ch(void);
int test_tls13_hrr_different_cs(void);

#define TEST_TLS13_DECLS                                   \
    TEST_DECL_GROUP("tls13", test_tls13_apis),             \
    TEST_DECL_GROUP("tls13", test_tls13_cipher_suites),    \
    TEST_DECL_GROUP("tls13", test_tls13_bad_psk_binder),   \
    TEST_DECL_GROUP("tls13", test_tls13_rpk_handshake),    \
    TEST_DECL_GROUP("tls13", test_tls13_pq_groups),        \
    TEST_DECL_GROUP("tls13", test_tls13_early_data),       \
    TEST_DECL_GROUP("tls13", test_tls13_same_ch),          \
    TEST_DECL_GROUP("tls13", test_tls13_hrr_different_cs)

#endif /* WOLFCRYPT_TEST_TLS13_H */
