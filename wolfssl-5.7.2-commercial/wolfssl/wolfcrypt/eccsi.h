/* eccsi.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/*!
    \file wolfssl/wolfcrypt/eccsi.h
*/


#ifndef WOLF_CRYPT_ECCSI_H
#define WOLF_CRYPT_ECCSI_H

#include <wolfssl/wolfcrypt/types.h>

#ifdef WOLFCRYPT_HAVE_ECCSI

#include <wolfssl/wolfcrypt/wolfmath.h>
#include <wolfssl/wolfcrypt/ecc.h>
#include <wolfssl/wolfcrypt/hash.h>
#include <wolfssl/wolfcrypt/hmac.h>

#define WOLFCRYPT_ECCSI_KMS
#define WOLFCRYPT_ECCSI_CLIENT

#define MAX_ECCSI_BYTES  (256 / 8)

/* Maximum number of loops of attempting to generate key pairs and signatures.
 */
#ifndef ECCSI_MAX_GEN_COUNT
    #define ECCSI_MAX_GEN_COUNT     10
#endif

typedef struct EccsiKeyParams {
    /** Order (q) of elliptic curve as an MP integer. */
    mp_int order;
#ifdef WOLFCRYPT_ECCSI_CLIENT
    /** A parameter of elliptic curve as an MP integer. */
    mp_int a;
    /** P parameter of elliptic curve as an MP integer. */
    mp_int b;
    /** Prime of elliptic curve as an MP integer. */
    mp_int prime;
#endif
    /** Base point for elliptic curve operations as an ECC point. */
    ecc_point* base;

    /** Bit indicates order (q) is set as an MP integer in ECCSI key. */
    byte haveOrder:1;
    /** Bit indicates A is set as an MP integer in ECCSI key. */
    byte haveA:1;
    /** Bit indicates B is set as an MP integer in ECCSI key. */
    byte haveB:1;
    /** Bit indicates prime is set as an MP integer in ECCSI key. */
    byte havePrime:1;
    /** Bit indicates base point is set as an MP integer in ECCSI key. */
    byte haveBase:1;
} EccsiKeyParams;

/**
 * ECCSI key.
 */
typedef struct EccsiKey {
    /** ECC key to perform elliptic curve operations with. */
    ecc_key ecc;
    /** ECC key to perform public key elliptic curve operations with. */
    ecc_key pubkey;
    /** ECC parameter in forms that can be used in computation. */
    EccsiKeyParams params;
#ifdef WOLFCRYPT_ECCSI_CLIENT
    /** Temporary MP integer used during operations.. */
    mp_int tmp;
    /** Secret Signing Key */
    mp_int ssk;
    /** Public Validation Token (PVT) */
    ecc_point* pvt;
#endif
    /** Generic hash algorithm object. */
    wc_HashAlg hash;
    /** Temporary buffer for use in operations. */
    byte data[(MAX_ECCSI_BYTES * 2) + 1];
#ifdef WOLFCRYPT_ECCSI_CLIENT
    /** Hash of identity - used in signing/verification. */
    byte idHash[WC_MAX_DIGEST_SIZE];
    /** Size of hash of identity in bytes. */
    byte idHashSz;
#endif
    /** Heap hint for dynamic memory allocation. */
    void* heap;
    /** Bit indicates KPAK (public key) is in montgomery form. */
    word16 kpakMont:1;
} EccsiKey;

#ifdef __cplusplus
    extern "C" {
#endif

WOLFSSL_API int wc_InitEccsiKey(EccsiKey* key, void* heap, int devId);
WOLFSSL_API int wc_InitEccsiKey_ex(EccsiKey* key, int keySz, int curveId,
        void* heap, int devId);
WOLFSSL_API void wc_FreeEccsiKey(EccsiKey* key);

WOLFSSL_API int wc_MakeEccsiKey(EccsiKey* key, WC_RNG* rng);

WOLFSSL_API int wc_MakeEccsiPair(EccsiKey* key, WC_RNG* rng,
        enum wc_HashType hashType, const byte* id, word32 idSz, mp_int* ssk,
        ecc_point* pvt);
WOLFSSL_API int wc_ValidateEccsiPair(EccsiKey* key, enum wc_HashType hashType,
        const byte* id, word32 idSz, const mp_int* ssk, ecc_point* pvt,
        int* valid);
WOLFSSL_API int wc_ValidateEccsiPvt(EccsiKey* key, const ecc_point* pvt,
        int* valid);
WOLFSSL_API int wc_EncodeEccsiPair(const EccsiKey* key, mp_int* ssk,
        ecc_point* pvt, byte* data, word32* sz);
WOLFSSL_API int wc_EncodeEccsiSsk(const EccsiKey* key, mp_int* ssk, byte* data,
        word32* sz);
WOLFSSL_API int wc_EncodeEccsiPvt(const EccsiKey* key, ecc_point* pvt,
        byte* data, word32* sz, int raw);
WOLFSSL_API int wc_DecodeEccsiPair(const EccsiKey* key, const byte* data,
        word32 sz, mp_int* ssk, ecc_point* pvt);
WOLFSSL_API int wc_DecodeEccsiSsk(const EccsiKey* key, const byte* data,
        word32 sz, mp_int* ssk);
WOLFSSL_API int wc_DecodeEccsiPvt(const EccsiKey* key, const byte* data,
        word32 sz, ecc_point* pvt);
WOLFSSL_API int wc_DecodeEccsiPvtFromSig(const EccsiKey* key, const byte* sig,
        word32 sz, ecc_point* pvt);

WOLFSSL_API int wc_ExportEccsiKey(EccsiKey* key, byte* data, word32* sz);
WOLFSSL_API int wc_ImportEccsiKey(EccsiKey* key, const byte* data, word32 sz);

WOLFSSL_API int wc_ExportEccsiPrivateKey(EccsiKey* key, byte* data, word32* sz);
WOLFSSL_API int wc_ImportEccsiPrivateKey(EccsiKey* key, const byte* data,
        word32 sz);

WOLFSSL_API int wc_ExportEccsiPublicKey(EccsiKey* key, byte* data, word32* sz,
        int raw);
WOLFSSL_API int wc_ImportEccsiPublicKey(EccsiKey* key, const byte* data,
        word32 sz, int trusted);

WOLFSSL_API int wc_HashEccsiId(EccsiKey* key, enum wc_HashType hashType,
        const byte* id, word32 idSz, ecc_point* pvt, byte* hash, byte* hashSz);
WOLFSSL_API int wc_SetEccsiHash(EccsiKey* key, const byte* hash, byte hashSz);
WOLFSSL_API int wc_SetEccsiPair(EccsiKey* key, const mp_int* ssk,
        const ecc_point* pvt);

WOLFSSL_API int wc_SignEccsiHash(EccsiKey* key, WC_RNG* rng,
        enum wc_HashType hashType, const byte* msg, word32 msgSz, byte* sig,
        word32* sigSz);
WOLFSSL_API int wc_VerifyEccsiHash(EccsiKey* key, enum wc_HashType hashType,
        const byte* msg, word32 msgSz, const byte* sig, word32 sigSz,
        int* verified);

#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* WOLFCRYPT_HAVE_ECCSI */

#endif /* WOLF_CRYPT_ECCSI_H */

