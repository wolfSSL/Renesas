/* user_settings.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
/* Operating Environment and Threading */
#define FREERTOS
#define FREERTOS_TCP

#define NO_MAIN_DRIVER
#define BENCH_EMBEDDED
#define NO_WRITEV

#define NO_DEV_RANDOM
#define SIZEOF_LONG_LONG 8
#define NO_WOLFSSL_DIR
#define WOLFSSL_NO_CURRDIR
#define NO_WOLF_C99
#define NO_MULTIBYTE_PRINT
#define NO_FILESYSTEM

#define XVALIDATEDATE(d, f,t) (0)

#define TFM_TIMING_RESISTANT
#define ECC_TIMING_RESISTANT
#define WC_RSA_BLINDING

#define HAVE_AESGCM
#define WOLFSSL_SHA512
#define HAVE_ECC
#define HAVE_CURVE25519
#define CURVE25519_SMALL

#define WOLFSSL_SMALL_STACK
#define USE_FAST_MATH

/* static RSA */
#define WOLFSSL_STATIC_RSA

/* SEGGER printf */
#define USE_SEGGER_RTT_PRINTF

#ifdef USE_SEGGER_RTT_PRINTF
    int myprintf(const char * sFormat, ...);
    #undef printf
    #define printf myprintf
#endif

/* #define WOLFSSL_TLS13 */

#if defined(WOLFSSL_TLS13)
    #include <sys/time.h>
    #define HAVE_FFDHE_2048
    #define HAVE_HKDF
    #define WC_RSA_PSS
    #define HAVE_TLS_EXTENSIONS
    #define HAVE_SUPPORTED_CURVES
#endif

#define WOLF_CRYPTO_CB
/* Enable SCEKEY_INSTALLED if keys are installed */
#define SCEKEY_INSTALLED
#if defined(WOLFSSL_RENESAS_SCEPROTECT) && defined(SCEKEY_INSTALLED)
    #define HAVE_RENESAS_SYNC
#endif
