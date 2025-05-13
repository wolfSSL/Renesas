/* test_dtls.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef TESTS_API_DTLS_H
#define TESTS_API_DTLS_H

int test_dtls12_basic_connection_id(void);
int test_dtls13_basic_connection_id(void);
int test_wolfSSL_dtls_cid_parse(void);
int test_dtls13_epochs(void);
int test_dtls13_ack_order(void);

#endif /* TESTS_API_DTLS_H */
