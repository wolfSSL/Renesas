/* coding.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/*!
    \file wolfssl/wolfcrypt/coding.h
*/

#ifndef WOLF_CRYPT_CODING_H
#define WOLF_CRYPT_CODING_H

#include <wolfssl/wolfcrypt/types.h>

#ifdef __cplusplus
    extern "C" {
#endif

#ifdef WOLFSSL_API_PREFIX_MAP
    #define Base64_Decode wc_Base64_Decode
    #define Base64_Decode_nonCT wc_Base64_Decode_nonCT
#endif

WOLFSSL_API int Base64_Decode(const byte* in, word32 inLen, byte* out,
                               word32* outLen);

WOLFSSL_API int Base64_Decode_nonCT(const byte* in, word32 inLen, byte* out,
                               word32* outLen);

#if defined(OPENSSL_EXTRA) || defined(SESSION_CERTS) || defined(WOLFSSL_KEY_GEN) \
   || defined(WOLFSSL_CERT_GEN) || defined(HAVE_WEBSERVER) || !defined(NO_DSA)
    #ifndef WOLFSSL_BASE64_ENCODE
        #define WOLFSSL_BASE64_ENCODE
    #endif
#endif


#ifdef WOLFSSL_BASE64_ENCODE
    enum Escaped {
        WC_STD_ENC = 0,       /* normal \n line ending encoding */
        WC_ESC_NL_ENC,        /* use escape sequence encoding   */
        WC_NO_NL_ENC          /* no encoding at all             */
    }; /* Encoding types */

    #ifdef WOLFSSL_API_PREFIX_MAP
        #define Base64_Encode wc_Base64_Encode
        #define Base64_EncodeEsc wc_Base64_EncodeEsc
        #define Base64_Encode_NoNl wc_Base64_Encode_NoNl
    #endif

    /* encode isn't */
    WOLFSSL_API
    int Base64_Encode(const byte* in, word32 inLen, byte* out,
                                  word32* outLen);
    WOLFSSL_API
    int Base64_EncodeEsc(const byte* in, word32 inLen, byte* out,
                                  word32* outLen);
    WOLFSSL_API
    int Base64_Encode_NoNl(const byte* in, word32 inLen, byte* out,
                                  word32* outLen);
#endif

#if defined(OPENSSL_EXTRA) || defined(OPENSSL_EXTRA_X509_SMALL) || \
    defined(HAVE_WEBSERVER) || defined(HAVE_FIPS) || \
    defined(HAVE_ECC_CDH) || defined(HAVE_SELFTEST) || \
    defined(WOLFSSL_ENCRYPTED_KEYS)
    #ifndef WOLFSSL_BASE16
        #define WOLFSSL_BASE16
    #endif
#endif

#ifdef WOLFSSL_BASE16
    #ifdef WOLFSSL_API_PREFIX_MAP
        #define Base16_Decode wc_Base16_Decode
        #define Base16_Encode wc_Base16_Encode
    #endif
    WOLFSSL_API
    int Base16_Decode(const byte* in, word32 inLen, byte* out, word32* outLen);
    WOLFSSL_API
    int Base16_Encode(const byte* in, word32 inLen, byte* out, word32* outLen);
#endif

WOLFSSL_LOCAL int Base64_SkipNewline(const byte* in, word32* inLen,
            word32* outJ);

#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* WOLF_CRYPT_CODING_H */

