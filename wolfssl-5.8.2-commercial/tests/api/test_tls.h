/* test_tls.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef TESTS_API_TEST_TLS_H
#define TESTS_API_TEST_TLS_H

int test_tls12_unexpected_ccs(void);
int test_tls13_unexpected_ccs(void);
int test_tls12_curve_intersection(void);
int test_tls13_curve_intersection(void);

#endif /* TESTS_API_TEST_TLS_EMS_H */
