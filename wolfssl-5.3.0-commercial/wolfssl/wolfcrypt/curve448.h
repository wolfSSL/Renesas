/* curve448.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* Implemented to: RFC 7748 */


#ifndef WOLF_CRYPT_CURVE448_H
#define WOLF_CRYPT_CURVE448_H

#include <wolfssl/wolfcrypt/types.h>

#ifdef HAVE_CURVE448

#include <wolfssl/wolfcrypt/fe_448.h>
#include <wolfssl/wolfcrypt/random.h>

#ifdef WOLFSSL_ASYNC_CRYPT
    #include <wolfssl/wolfcrypt/async.h>
#endif

#ifdef __cplusplus
    extern "C" {
#endif

#define CURVE448_KEY_SIZE        56
#define CURVE448_PUB_KEY_SIZE    56

#ifndef WC_CURVE448KEY_TYPE_DEFINED
    typedef struct curve448_key curve448_key;
    #define WC_CURVE448KEY_TYPE_DEFINED
#endif

/* A CURVE448 Key */
struct curve448_key {
    byte p[CURVE448_PUB_KEY_SIZE];  /* public key  */
    byte k[CURVE448_KEY_SIZE];      /* private key */

#ifdef WOLFSSL_ASYNC_CRYPT
    WC_ASYNC_DEV asyncDev;
#endif

    /* bit fields */
    byte pubSet:1;
    byte privSet:1;
};

enum {
    EC448_LITTLE_ENDIAN = 0,
    EC448_BIG_ENDIAN    = 1
};

WOLFSSL_API
int wc_curve448_make_key(WC_RNG* rng, int keysize, curve448_key* key);

WOLFSSL_API
int wc_curve448_make_pub(int public_size, byte* pub, int private_size,
                           const byte* priv);

WOLFSSL_API
int wc_curve448_shared_secret(curve448_key* private_key,
                              curve448_key* public_key,
                              byte* out, word32* outlen);

WOLFSSL_API
int wc_curve448_shared_secret_ex(curve448_key* private_key,
                                 curve448_key* public_key,
                                 byte* out, word32* outlen, int endian);

WOLFSSL_API
int wc_curve448_init(curve448_key* key);

WOLFSSL_API
void wc_curve448_free(curve448_key* key);


/* raw key helpers */
WOLFSSL_API
int wc_curve448_import_private(const byte* priv, word32 privSz,
                               curve448_key* key);
WOLFSSL_API
int wc_curve448_import_private_ex(const byte* priv, word32 privSz,
                                  curve448_key* key, int endian);

WOLFSSL_API
int wc_curve448_import_private_raw(const byte* priv, word32 privSz,
                                   const byte* pub, word32 pubSz,
                                   curve448_key* key);
WOLFSSL_API
int wc_curve448_import_private_raw_ex(const byte* priv, word32 privSz,
                                      const byte* pub, word32 pubSz,
                                      curve448_key* key, int endian);
WOLFSSL_API
int wc_curve448_export_private_raw(curve448_key* key, byte* out,
                                   word32* outLen);
WOLFSSL_API
int wc_curve448_export_private_raw_ex(curve448_key* key, byte* out,
                                      word32* outLen, int endian);

WOLFSSL_API
int wc_curve448_import_public(const byte* in, word32 inLen,
                              curve448_key* key);
WOLFSSL_API
int wc_curve448_import_public_ex(const byte* in, word32 inLen,
                                 curve448_key* key, int endian);
WOLFSSL_API
int wc_curve448_check_public(const byte* pub, word32 pubSz, int endian);

WOLFSSL_API
int wc_curve448_export_public(curve448_key* key, byte* out, word32* outLen);
WOLFSSL_API
int wc_curve448_export_public_ex(curve448_key* key, byte* out,
                                 word32* outLen, int endian);

WOLFSSL_API
int wc_curve448_export_key_raw(curve448_key* key,
                               byte* priv, word32 *privSz,
                               byte* pub, word32 *pubSz);
WOLFSSL_API
int wc_curve448_export_key_raw_ex(curve448_key* key,
                                  byte* priv, word32 *privSz,
                                  byte* pub, word32 *pubSz,
                                  int endian);
/* size helper */
WOLFSSL_API
int wc_curve448_size(curve448_key* key);

#ifdef __cplusplus
    }    /* extern "C" */
#endif

#endif /* HAVE_CURVE448 */
#endif /* WOLF_CRYPT_CURVE448_H */

