/* user_settings_wolfboot_keytools.h
 *
 * wolfCrypt build settings for wolfBoot keygen and signing tool
 * Enabled via WOLFSSL_USER_SETTINGS.
 *
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef H_USER_SETTINGS_
#define H_USER_SETTINGS_

#include <stdint.h>

/* System */
#define WOLFSSL_GENERAL_ALIGNMENT 4
#define SINGLE_THREADED
#define WOLFCRYPT_ONLY
#define SIZEOF_LONG_LONG 8

/* Math */
#define WOLFSSL_SP
#define WOLFSSL_SP_NO_3072
#define USE_FAST_MATH
#define FP_MAX_BITS (4096 * 2)
#define TFM_TIMING_RESISTANT

/* ECC */
#define HAVE_ECC
#define WOLFSSL_HAVE_SP_ECC
#define ECC_TIMING_RESISTANT

/* ED25519 */
#define HAVE_ED25519
#define CURVED25519_SMALL

/* RSA */
#define HAVE_RSA
#define WOLFSSL_HAVE_SP_RSA
#define WC_RSA_BLINDING
#define WOLFSSL_KEY_GEN

/* Hashing */
#define WOLFSSL_SHA512 /* Required for ED25519 */
#define WOLFSSL_SHA3
#undef  NO_SHA256

/* Chacha stream cipher */
#define HAVE_CHACHA

/* Disables */
#define NO_AES
#define NO_CMAC
#define NO_HMAC
#define NO_RC4
#define NO_SHA
#define NO_DH
#define NO_DSA
#define NO_MD4
#define NO_RABBIT
#define NO_MD5
#define NO_SIG_WRAPPER
#define NO_CERT
#define NO_SESSION_CACHE
#define NO_HC128
#define NO_DES3
#define NO_PWDBASED
#define NO_WRITEV
#define NO_FILESYSTEM
//#define NO_MAIN_DRIVER
#define NO_OLD_RNGNAME
#define NO_WOLFSSL_DIR
#define WOLFSSL_NO_SOCK
#define WOLFSSL_IGNORE_FILE_WARN
#define NO_ERROR_STRINGS

#define BENCH_EMBEDDED
#define NO_CRYPT_TEST
#define NO_CRYPT_BENCHMARK

#endif /* !H_USER_SETTINGS_ */
