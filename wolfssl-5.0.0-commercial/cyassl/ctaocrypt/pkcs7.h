/* pkcs7.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifdef HAVE_PKCS7

#ifndef CTAO_CRYPT_PKCS7_H
#define CTAO_CRYPT_PKCS7_H

/* pull in compatibility for old includes */
#include <cyassl/ctaocrypt/types.h>
#include <cyassl/ctaocrypt/asn.h>
#include <cyassl/ctaocrypt/asn_public.h>
#include <cyassl/ctaocrypt/random.h>
#include <cyassl/ctaocrypt/des3.h>

#include <wolfssl/wolfcrypt/pkcs7.h>

/* for pkcs7 reverse compatibility */
#define SetContentType      wc_SetContentType
#define GetContentType      wc_GetContentType
#define CreateRecipientInfo wc_CreateRecipientInfo
#define PKCS7_InitWithCert  wc_PKCS7_InitWithCert
#define PKCS7_Free          wc_PKCS7_Free
#define PKCS7_EncodeData    wc_PKCS7_EncodeData
#define PKCS7_EncodeSignedData    wc_PKCS7_EncodeSignedData
#define PKCS7_VerifySignedData    wc_PKCS7_VerifySignedData
#define PKCS7_EncodeEnvelopedData wc_PKCS7_EncodeEnvelopedData
#define PKCS7_DecodeEnvelopedData wc_PKCS7_DecodeEnvelopedData

#endif /* CTAO_CRYPT_PKCS7_H */

#endif /* HAVE_PKCS7 */

