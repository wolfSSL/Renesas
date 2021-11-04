/* aes.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifndef NO_AES

#ifndef CTAO_CRYPT_AES_H
#define CTAO_CRYPT_AES_H

#include <wolfssl/wolfcrypt/aes.h>
#define AesSetKey            wc_AesSetKey
#define AesSetIV             wc_AesSetIV
#define AesCbcEncrypt        wc_AesCbcEncrypt
#define AesCbcDecrypt        wc_AesCbcDecrypt
#define AesCbcDecryptWithKey wc_AesCbcDecryptWithKey

/* AES-CTR */
#ifdef WOLFSSL_AES_COUNTER
    #define AesCtrEncrypt wc_AesCtrEncrypt
#endif
/* AES-DIRECT */
#if defined(WOLFSSL_AES_DIRECT)
    #define AesEncryptDirect wc_AesEncryptDirect
    #define AesDecryptDirect wc_AesDecryptDirect
    #define AesSetKeyDirect  wc_AesSetKeyDirect
#endif
#ifdef HAVE_AESGCM
    #define AesGcmSetKey  wc_AesGcmSetKey
    #define AesGcmEncrypt wc_AesGcmEncrypt
    #define AesGcmDecrypt wc_AesGcmDecrypt
    #define GmacSetKey    wc_GmacSetKey
    #define GmacUpdate    wc_GmacUpdate
#endif /* HAVE_AESGCM */
#ifdef HAVE_AESCCM
    #define AesCcmSetKey  wc_AesCcmSetKey
    #define AesCcmEncrypt wc_AesCcmEncrypt
    #define AesCcmDecrypt wc_AesCcmDecrypt
#endif /* HAVE_AESCCM */

#endif /* CTAO_CRYPT_AES_H */
#endif /* NO_AES */

