/* test_x509.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_X509_H
#define WOLFCRYPT_TEST_X509_H

int test_x509_rfc2818_verification_callback(void);

#define TEST_X509_DECLS                                                        \
    TEST_DECL_GROUP("x509", test_x509_rfc2818_verification_callback)

#endif /* WOLFCRYPT_TEST_X509_H */
