/* test_signature.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_SIGNATURE_H
#define WOLFCRYPT_TEST_SIGNATURE_H

#include <tests/api/api_decl.h>

int test_wc_SignatureGetSize_ecc(void);
int test_wc_SignatureGetSize_rsa(void);

#define TEST_SIGNATURE_DECLS                                    \
    TEST_DECL_GROUP("signature", test_wc_SignatureGetSize_ecc), \
    TEST_DECL_GROUP("signature", test_wc_SignatureGetSize_ecc)

#endif /* WOLFCRYPT_TEST_SIGNATURE_H */
