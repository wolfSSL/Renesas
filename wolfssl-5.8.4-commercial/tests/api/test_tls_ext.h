/* test_tls_ext.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef TESTS_API_TEST_TLS_EXT_H
#define TESTS_API_TEST_TLS_EXT_H

int test_tls_ems_downgrade(void);
int test_wolfSSL_DisableExtendedMasterSecret(void);
int test_certificate_authorities_certificate_request(void);
int test_certificate_authorities_client_hello(void);

#endif /* TESTS_API_TEST_TLS_EMS_H */
