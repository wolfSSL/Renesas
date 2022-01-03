/* user_rsa.h
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
 Created to use intel's IPP see their license for linking to intel's IPP library
 */

#ifndef USER_WOLF_CRYPT_RSA_H
#define USER_WOLF_CRYPT_RSA_H

#include <wolfssl/wolfcrypt/settings.h>

#ifndef NO_RSA

#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/random.h>

/* intels crypto */
#include <ipp.h>
#include <ippcp.h>

#ifdef __cplusplus
    extern "C" {
#endif

/* needed for WOLFSSL_RSA type but use macro guard against redefine */
#if defined(OPENSSL_EXTRA) && !defined(WOLFSSL_TYPES_DEFINED) \
        && !defined(WOLFSSL_RSA_TYPE_DEFINED)
    struct WOLFSSL_RSA;
    typedef struct WOLFSSL_RSA WOLFSSL_RSA;
    #define WOLFSSL_RSA_TYPE_DEFINED
#endif


enum {
    RSA_PUBLIC   = 0,
    RSA_PRIVATE  = 1,
};

/* RSA */
struct RsaKey {
    IppsBigNumState* n;
    IppsBigNumState* e;
    IppsBigNumState* dipp;
    IppsBigNumState* pipp;
    IppsBigNumState* qipp;
    IppsBigNumState* dPipp;
    IppsBigNumState* dQipp;
    IppsBigNumState* uipp;
    int nSz, eSz, dSz;
    IppsRSAPublicKeyState*  pPub;
    IppsRSAPrivateKeyState* pPrv;
    word32 prvSz; /* size of private key */
    word32 sz;    /* size of signature */
    int   type;                               /* public or private */
    void* heap;                               /* for user memory overrides */
};

#ifndef WC_RSAKEY_TYPE_DEFINED
    typedef struct RsaKey RsaKey;
    #define WC_RSAKEY_TYPE_DEFINED
#endif

WOLFSSL_API int  wc_InitRsaKey(RsaKey* key, void*);
WOLFSSL_API int  wc_InitRsaKey_ex(RsaKey* key, void* heap, int devId);
WOLFSSL_API int  wc_FreeRsaKey(RsaKey* key);

WOLFSSL_API int  wc_RsaPublicEncrypt(const byte* in, word32 inLen, byte* out,
                                     word32 outLen, RsaKey* key, WC_RNG* rng);
WOLFSSL_API int  wc_RsaPrivateDecryptInline(byte* in, word32 inLen, byte** out,
                                            RsaKey* key);
WOLFSSL_API int  wc_RsaPrivateDecrypt(const byte* in, word32 inLen, byte* out,
                                      word32 outLen, RsaKey* key);
WOLFSSL_API int  wc_RsaSSL_Sign(const byte* in, word32 inLen, byte* out,
                                word32 outLen, RsaKey* key, WC_RNG* rng);
WOLFSSL_API int  wc_RsaSSL_VerifyInline(byte* in, word32 inLen, byte** out,
                                        RsaKey* key);
WOLFSSL_API int  wc_RsaSSL_Verify(const byte* in, word32 inLen, byte* out,
                                  word32 outLen, RsaKey* key);
WOLFSSL_API int  wc_RsaEncryptSize(RsaKey* key);

WOLFSSL_API int  wc_RsaPrivateKeyDecode(const byte* input, word32* inOutIdx,
                                                               RsaKey*, word32);
WOLFSSL_API int  wc_RsaPublicKeyDecode_ex(const byte* input, word32* inOutIdx,
        word32 inSz, const byte** n, word32* nSz, const byte** e, word32* eSz);
WOLFSSL_API int  wc_RsaPublicKeyDecode(const byte* input, word32* inOutIdx,
                                                               RsaKey*, word32);
WOLFSSL_API int  wc_RsaPublicKeyDecodeRaw(const byte* n, word32 nSz,
                                        const byte* e, word32 eSz, RsaKey* key);
WOLFSSL_API int wc_RsaKeyToDer(RsaKey*, byte* output, word32 inLen);
WOLFSSL_API int wc_RsaKeyToPublicDer(RsaKey*, byte* output, word32 inLen);
#ifdef WOLFSSL_KEY_GEN
    WOLFSSL_API int wc_MakeRsaKey(RsaKey* key, int size, long e, WC_RNG* rng);
#endif
WOLFSSL_API int  wc_RsaFlattenPublicKey(RsaKey*, byte*, word32*, byte*,
                                                                       word32*);
WOLFSSL_API int  wc_RsaSetRNG(RsaKey* key, WC_RNG* rng);


#if defined(WOLFSSL_CERT_GEN) || defined(WOLFSSL_KEY_GEN) || defined(OPENSSL_EXTRA)
        /* abstracted BN operations with RSA key */
    WOLFSSL_API int wc_Rsa_leading_bit(void* BN);
    WOLFSSL_API int wc_Rsa_unsigned_bin_size(void* BN);

        /* return MP_OKAY on success */
    WOLFSSL_API int wc_Rsa_to_unsigned_bin(void* BN, byte* in, int inLen);
#endif

#ifdef OPENSSL_EXTRA /* abstracted functions to deal with rsa key */
    WOLFSSL_API int SetRsaExternal(WOLFSSL_RSA* rsa);
    WOLFSSL_API int SetRsaInternal(WOLFSSL_RSA* rsa);
#endif
#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* NO_RSA */
#endif /* USER_WOLF_CRYPT_RSA_H */
