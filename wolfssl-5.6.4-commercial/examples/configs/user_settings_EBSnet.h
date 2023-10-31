/* user_settings_EBSnet.h
 *
 * Copyright (C) 2006-2023 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* Example wolfSSL user settings for use with EBSnet ports.
 * This file is included with wolfssl/wolfcrypt/settings.h when WOLFSSL_USER_SETTINGS is defined.
 */

#ifndef WOLFSSL_USER_SETTINGS_H
#define WOLFSSL_USER_SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

#define OPENSSL_EXTRA_X509_SMALL

#define USE_FAST_MATH
#define TFM_TIMING_RESISTANT
#define WC_RSA_BLINDING
#define ECC_TIMING_RESISTANT

#define HAVE_ECC
#define HAVE_CURVE25519
#define HAVE_AESGCM
#define WOLFSSL_SHA384

#define NO_DSA
#define NO_RC4
#define NO_MD4
#define NO_MD5
#define NO_DES3

#ifdef __cplusplus
}
#endif

#endif /* WOLFSSL_USER_SETTINGS_H */

