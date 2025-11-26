/* test_tls.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef TESTS_API_TEST_TLS_H
#define TESTS_API_TEST_TLS_H

int test_utils_memio_move_message(void);
int test_tls12_unexpected_ccs(void);
int test_tls13_unexpected_ccs(void);
int test_tls12_curve_intersection(void);
int test_tls13_curve_intersection(void);
int test_tls_certreq_order(void);
int test_tls12_bad_cv_sig_alg(void);

#define TEST_TLS_DECLS                                                         \
        TEST_DECL_GROUP("tls", test_utils_memio_move_message),                 \
        TEST_DECL_GROUP("tls", test_tls12_unexpected_ccs),                     \
        TEST_DECL_GROUP("tls", test_tls13_unexpected_ccs),                     \
        TEST_DECL_GROUP("tls", test_tls12_curve_intersection),                 \
        TEST_DECL_GROUP("tls", test_tls13_curve_intersection),                 \
        TEST_DECL_GROUP("tls", test_tls_certreq_order),                        \
        TEST_DECL_GROUP("tls", test_tls12_bad_cv_sig_alg)

#endif /* TESTS_API_TEST_TLS_H */
