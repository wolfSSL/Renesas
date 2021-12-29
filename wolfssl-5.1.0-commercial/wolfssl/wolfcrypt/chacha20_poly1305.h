/* chacha20_poly1305.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
/*

DESCRIPTION
This library contains implementation for the ChaCha20 stream cipher and
the Poly1305 authenticator, both as as combined-mode,
or Authenticated Encryption with Additional Data (AEAD) algorithm.

*/

/*!
    \file wolfssl/wolfcrypt/chacha20_poly1305.h
*/

#ifndef WOLF_CRYPT_CHACHA20_POLY1305_H
#define WOLF_CRYPT_CHACHA20_POLY1305_H

#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/chacha.h>
#include <wolfssl/wolfcrypt/poly1305.h>

#if defined(HAVE_CHACHA) && defined(HAVE_POLY1305)

#ifdef __cplusplus
    extern "C" {
#endif

#define CHACHA20_POLY1305_AEAD_KEYSIZE      32
#define CHACHA20_POLY1305_AEAD_IV_SIZE      12
#define CHACHA20_POLY1305_AEAD_AUTHTAG_SIZE 16
#define CHACHA20_POLY1305_MAX               4294967295U
#define XCHACHA20_POLY1305_AEAD_NONCE_SIZE  24

enum {
    CHACHA20_POLY_1305_ENC_TYPE = 8,    /* cipher unique type */

    /* AEAD Cipher Direction */
    CHACHA20_POLY1305_AEAD_DECRYPT = 0,
    CHACHA20_POLY1305_AEAD_ENCRYPT = 1,

    /* AEAD State */
    CHACHA20_POLY1305_STATE_INIT = 0,
    CHACHA20_POLY1305_STATE_READY = 1,
    CHACHA20_POLY1305_STATE_AAD = 2,
    CHACHA20_POLY1305_STATE_DATA = 3,
};

typedef struct ChaChaPoly_Aead {
    ChaCha   chacha;
    Poly1305 poly;

    word32   aadLen;
    word32   dataLen;

    byte     state;
    byte     isEncrypt:1;
} ChaChaPoly_Aead;


/*
 * The IV for this implementation is 96 bits to give the most flexibility.
 *
 * Some protocols may have unique per-invocation inputs that are not
 * 96-bit in length. For example, IPsec may specify a 64-bit nonce. In
 * such a case, it is up to the protocol document to define how to
 * transform the protocol nonce into a 96-bit nonce, for example by
 * concatenating a constant value.
 */

WOLFSSL_API
int wc_ChaCha20Poly1305_Encrypt(
                const byte inKey[CHACHA20_POLY1305_AEAD_KEYSIZE],
                const byte inIV[CHACHA20_POLY1305_AEAD_IV_SIZE],
                const byte* inAAD, const word32 inAADLen,
                const byte* inPlaintext, const word32 inPlaintextLen,
                byte* outCiphertext,
                byte outAuthTag[CHACHA20_POLY1305_AEAD_AUTHTAG_SIZE]);

WOLFSSL_API
int wc_ChaCha20Poly1305_Decrypt(
                const byte inKey[CHACHA20_POLY1305_AEAD_KEYSIZE],
                const byte inIV[CHACHA20_POLY1305_AEAD_IV_SIZE],
                const byte* inAAD, const word32 inAADLen,
                const byte* inCiphertext, const word32 inCiphertextLen,
                const byte inAuthTag[CHACHA20_POLY1305_AEAD_AUTHTAG_SIZE],
                byte* outPlaintext);

WOLFSSL_API
int wc_ChaCha20Poly1305_CheckTag(
    const byte authTag[CHACHA20_POLY1305_AEAD_AUTHTAG_SIZE],
    const byte authTagChk[CHACHA20_POLY1305_AEAD_AUTHTAG_SIZE]);



/* Implementation of AEAD, which includes support for adding
    data, then final calculation of authentication tag */
WOLFSSL_API int wc_ChaCha20Poly1305_Init(ChaChaPoly_Aead* aead,
    const byte inKey[CHACHA20_POLY1305_AEAD_KEYSIZE],
    const byte inIV[CHACHA20_POLY1305_AEAD_IV_SIZE],
    int isEncrypt);
WOLFSSL_API int wc_ChaCha20Poly1305_UpdateAad(ChaChaPoly_Aead* aead,
    const byte* inAAD, word32 inAADLen);
WOLFSSL_API int wc_ChaCha20Poly1305_UpdateData(ChaChaPoly_Aead* aead,
    const byte* inData, byte* outData, word32 dataLen);
WOLFSSL_API int wc_ChaCha20Poly1305_Final(ChaChaPoly_Aead* aead,
    byte outAuthTag[CHACHA20_POLY1305_AEAD_AUTHTAG_SIZE]);

#ifdef HAVE_XCHACHA

WOLFSSL_API int wc_XChaCha20Poly1305_Init(
    ChaChaPoly_Aead* aead,
    const byte *ad, word32 ad_len,
    const byte *inKey, word32 inKeySz,
    const byte *inIV, word32 inIVSz,
    int isEncrypt);

WOLFSSL_API int wc_XChaCha20Poly1305_Encrypt(
    byte *dst, const size_t dst_space,
    const byte *src, const size_t src_len,
    const byte *ad, const size_t ad_len,
    const byte *nonce, const size_t nonce_len,
    const byte *key, const size_t key_len);

WOLFSSL_API int wc_XChaCha20Poly1305_Decrypt(
    byte *dst, const size_t dst_space,
    const byte *src, const size_t src_len,
    const byte *ad, const size_t ad_len,
    const byte *nonce, const size_t nonce_len,
    const byte *key, const size_t key_len);

#endif /* HAVE_XCHACHA */

#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* HAVE_CHACHA && HAVE_POLY1305 */
#endif /* WOLF_CRYPT_CHACHA20_POLY1305_H */
