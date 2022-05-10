/* wolfcaam_aes.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#include <wolfssl/wolfcrypt/settings.h>

#ifndef WOLFCAAM_AES_H
#define WOLFCAAM_AES_H

#if !defined(NO_AES) && defined(WOLFSSL_CAAM)

#include <wolfssl/wolfcrypt/aes.h>

WOLFSSL_LOCAL int wc_CAAM_AesCcmEncrypt(Aes* aes, const byte* in, byte* out,
        word32 sz, const byte* nonce, word32 nonceSz, byte* authTag,
        word32 authTagSz, const byte* authIn, word32 authInSz);

WOLFSSL_LOCAL int wc_CAAM_AesCcmDecrypt(Aes* aes, const byte* in, byte* out,
        word32 sz, const byte* nonce, word32 nonceSz, const byte* authTag,
        word32 authTagSz, const byte* authIn, word32 authInSz);

WOLFSSL_LOCAL int wc_CAAM_AesGcmEncrypt(Aes* aes, const byte* in, byte* out,
        word32 sz, const byte* nonce, word32 nonceSz, byte* authTag,
        word32 authTagSz, const byte* authIn, word32 authInSz);

WOLFSSL_LOCAL int wc_CAAM_AesGcmDecrypt(Aes* aes, const byte* in, byte* out,
        word32 sz, const byte* nonce, word32 nonceSz, const byte* authTag,
        word32 authTagSz, const byte* authIn, word32 authInSz);

WOLFSSL_LOCAL int wc_CAAM_AesCbcEncrypt(Aes* aes, byte* out, const byte* in,
        word32 sz);

WOLFSSL_LOCAL int wc_CAAM_AesCbcDecrypt(Aes* aes, byte* out, const byte* in,
        word32 sz);

WOLFSSL_LOCAL int wc_CAAM_AesEcbEncrypt(Aes* aes, byte* out, const byte* in,
        word32 sz);

WOLFSSL_LOCAL int wc_CAAM_AesEcbDecrypt(Aes* aes, byte* out, const byte* in,
        word32 sz);
#endif /* WOLFSSL_CAAM && !NO_AES */
#endif /* WOLFCAAM_AES_H */

