/* kdf.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFSSL_KDF_H_
#define WOLFSSL_KDF_H_

#ifdef __cplusplus
    extern "C" {
#endif

#define WOLFSSL_EVP_PKEY_HKDEF_MODE_EXTRACT_AND_EXPAND 0
#define WOLFSSL_EVP_PKEY_HKDEF_MODE_EXTRACT_ONLY 1
#define WOLFSSL_EVP_PKEY_HKDEF_MODE_EXPAND_ONLY 2

#ifndef OPENSSL_COEXIST

#define EVP_PKEY_HKDEF_MODE_EXTRACT_AND_EXPAND WOLFSSL_EVP_PKEY_HKDEF_MODE_EXTRACT_AND_EXPAND
#define EVP_PKEY_HKDEF_MODE_EXTRACT_ONLY WOLFSSL_EVP_PKEY_HKDEF_MODE_EXTRACT_ONLY
#define EVP_PKEY_HKDEF_MODE_EXPAND_ONLY WOLFSSL_EVP_PKEY_HKDEF_MODE_EXPAND_ONLY

#endif /* !OPENSSL_COEXIST */

#ifdef __cplusplus
    }  /* extern "C" */
#endif

#endif /* WOLFSSL_KDF_H_ */
