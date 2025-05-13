/* user_settings.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* These are the build settings used by the Visual Studio CSharp wrapper */

#ifndef _WIN_CSHARP_USER_SETTINGS_H_
#define _WIN_CSHARP_USER_SETTINGS_H_

/* Features */
#define NO_OLD_TLS
#define WOLFSSL_TLS13
#define WOLFSSL_DTLS
#define WOLFSSL_DTLS13
#define WOLFSSL_SEND_HRR_COOKIE
#define WOLFSSL_DTLS_CID
#define HAVE_EXTENDED_MASTER
#define HAVE_SECURE_RENEGOTIATION
#define HAVE_SUPPORTED_CURVES
#define HAVE_TLS_EXTENSIONS
#define WOLFSSL_CERT_EXT
#define WOLFSSL_CERT_REQ
#define WOLFSSL_CERT_GEN
#define HAVE_ENCRYPT_THEN_MAC
#define HAVE_ECC_ENCRYPT
#define WOLFSSL_PUBLIC_MP
#define NO_MULTIBYTE_PRINT
#define WOLFSSL_KEY_GEN /* RSA key gen */
#define WOLFSSL_ASN_TEMPLATE /* default */
#define WOLFSSL_SHA3

#if 0
    #define OPENSSL_EXTRA
#endif

#define HAVE_CRL
#if 0
    /* start thread that can monitor CRL directory */
    #define HAVE_CRL_MONITOR
#endif

/* Algorithms */
#define HAVE_ED25519
#define HAVE_CURVE25519

#define HAVE_AESGCM
#define WOLFSSL_AESGCM_STREAM
#define WOLFSSL_SHA384
#define WOLFSSL_SHA512

#define HAVE_HKDF

#undef  NO_DH
#define HAVE_PUBLIC_FFDHE
#define HAVE_FFDHE_2048
#define HAVE_FFDHE_4096

#undef  NO_RSA
#define WC_RSA_PSS
#define WOLFSSL_PSS_LONG_SALT
#define WC_RSA_BLINDING

#define HAVE_ECC
#define ECC_SHAMIR
#define ECC_TIMING_RESISTANT
#define HAVE_COMP_KEY

/* Disable features */
#define NO_PSK

/* Disable Algorithms */
#define NO_DES3
#define NO_DSA
#define NO_RC4
#define NO_MD4
#define NO_MD5
#define NO_SHA

/* Math */

/* Single Precision Support for RSA/DH 1024/2048/3072 and
 * ECC P-256/P-384 */
#define WOLFSSL_HAVE_SP_ECC
#define WOLFSSL_HAVE_SP_DH
#define WOLFSSL_HAVE_SP_RSA

/* Optional Performance Speedups */
#if 0
    #ifdef _WIN64
        /* Assembly speedups for SP math */
        #define WOLFSSL_SP_X86_64_ASM

        /* Support for RDSEED instruction */
        #define HAVE_INTEL_RDSEED

        /* AESNI on x64 */
        #define WOLFSSL_AESNI

        /* Intel ASM */
        #define USE_INTEL_SPEEDUP
        #define WOLFSSL_X86_64_BUILD

        /* Old versions of MASM compiler do not recognize newer
         * instructions. */
        #if 0
            #define NO_AVX2_SUPPORT
            #define NO_MOVBE_SUPPORT
        #endif
    #endif
#endif

/* Debug logging */
#if 1
    #define DEBUG_WOLFSSL
#else
    /* #define NO_ERROR_STRINGS */
#endif

#endif /* !_WIN_CSHARP_USER_SETTINGS_H_ */
