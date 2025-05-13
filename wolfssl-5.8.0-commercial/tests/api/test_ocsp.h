/* test_ocsp.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFSSL_TEST_OCSP_H
#define WOLFSSL_TEST_OCSP_H

int test_ocsp_certid_enc_dec(void);
int test_ocsp_status_callback(void);
int test_ocsp_basic_verify(void);
int test_ocsp_response_parsing(void);
#endif /* WOLFSSL_TEST_OCSP_H */

