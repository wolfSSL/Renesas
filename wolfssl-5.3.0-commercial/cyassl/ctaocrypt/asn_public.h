/* asn_public.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifndef CTAO_CRYPT_ASN_PUBLIC_H
#define CTAO_CRYPT_ASN_PUBLIC_H

/* pull in compatibility for each of the includes */
#include <cyassl/ctaocrypt/types.h>
#include <cyassl/ctaocrypt/types.h>
#include <cyassl/ctaocrypt/ecc.h>
#ifdef WOLFSSL_CERT_GEN
    #include <cyassl/ctaocrypt/rsa.h>
#endif

#include <wolfssl/wolfcrypt/asn_public.h>
#ifdef WOLFSSL_CERT_GEN
    #define InitCert wc_InitCert
    #define MakeCert wc_MakeCert

    #ifdef WOLFSSL_CERT_REQ
    #define MakeCertReq wc_MakeCertReq
#endif

    #define SignCert     wc_SignCert
    #define MakeSelfCert wc_MakeSelfCert
    #define SetIssuer    wc_SetIssuer
    #define SetSubject   wc_SetSubject

    #ifdef WOLFSSL_ALT_NAMES
    #define SetAltNames wc_SetAltNames
#endif

    #define SetIssuerBuffer   wc_SetIssuerBuffer
    #define SetSubjectBuffer  wc_SetSubjectBuffer
    #define SetAltNamesBuffer wc_SetAltNamesBuffer
    #define SetDatesBuffer    wc_SetDatesBuffer

#endif /* WOLFSSL_CERT_GEN */

    #if defined(WOLFSSL_KEY_GEN) || defined(WOLFSSL_CERT_GEN)
    #define DerToPem wc_DerToPem
#endif

#ifdef HAVE_ECC
    /* private key helpers */
    #define EccPrivateKeyDecode wc_EccPrivateKeyDecode
    #define EccKeyToDer         wc_EccKeyToDer
#endif

    /* DER encode signature */
    #define EncodeSignature wc_EncodeSignature
    #define GetCTC_HashOID  wc_GetCTC_HashOID

#endif /* CTAO_CRYPT_ASN_PUBLIC_H */

