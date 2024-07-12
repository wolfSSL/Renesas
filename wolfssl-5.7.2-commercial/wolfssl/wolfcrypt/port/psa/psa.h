/* psa.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/**
 * Platform Security Architecture (PSA) header
 *
 * If WOLFSSL_HAVE_PSA is defined, wolfSSL can use the cryptographic primitives
 * exported by a PSA Crypto API.
 *
 * Defines:
 *
 * WOLFSSL_HAVE_PSA: Global switch to enable PSA
 * WOLFSSL_PSA_NO_RNG: disable PSA random generator support
 * WOLFSSL_PSA_NO_HASH: disable PSA hashing support
 * WOLFSSL_PSA_NO_AES: disable PSA AES support
 * WOLFSSL_PSA_GLOBAL_LOCK: serialize the access to the underlying PSA lib
 * WOLFSSL_PSA_NO_PKCBS: disable PK callbacks support
 */

#ifndef WOLFSSL_PSA_H
#define WOLFSSL_PSA_H

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wolfssl/wolfcrypt/types.h>

#if defined(WOLFSSL_HAVE_PSA)

#include <psa/crypto.h>
#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/visibility.h>

#if !defined(WOLFSSL_PSA_NO_AES)
#if !defined(NO_AES)
#include <wolfssl/wolfcrypt/aes.h>
#endif
#endif /* WOLFSSL_PSA_NO_AES */

#if !defined(WOLFSSL_PSA_NO_PKCB)
#include <wolfssl/ssl.h>
#endif

#ifndef PSA_ALG_NONE
    #define PSA_ALG_NONE ((psa_algorithm_t)0)
#endif
#ifndef PSA_KEY_ID_NULL
    #define PSA_KEY_ID_NULL ((psa_key_id_t)0)
#endif

#if defined(WOLFSSL_PSA_GLOBAL_LOCK)
void PSA_LOCK(void);
void PSA_UNLOCK(void);
#else
#define PSA_LOCK() WC_DO_NOTHING
#define PSA_UNLOCK() WC_DO_NOTHING
#endif

int wc_psa_init(void);

#if !defined(WOLFSSL_PSA_NO_RNG)

WOLFSSL_API int wc_psa_get_random(unsigned char *out, word32 sz);
#ifndef HAVE_HASHDRBG
#define CUSTOM_RAND_GENERATE_BLOCK wc_psa_get_random
#else
#define CUSTOM_RAND_GENERATE_SEED wc_psa_get_random
#endif

#endif /* WOLFSSL_HAVE_PSA_RNG */

#if !defined(WOLFSSL_PSA_NO_AES) && !defined(NO_AES)

int wc_psa_aes_init(Aes *aes);
int wc_psa_aes_free(Aes *aes);
int wc_psa_aes_get_key_size(Aes *aes, word32 *keySize);
int wc_psa_aes_set_key(Aes *aes, const uint8_t *key,
                       size_t key_length, uint8_t *iv,
                       psa_algorithm_t alg, int dir);

WOLFSSL_API int wc_psa_aes_encrypt_decrypt(Aes *aes, const uint8_t *input,
                                           uint8_t *output, size_t length,
                                           psa_algorithm_t alg, int direction);

WOLFSSL_API int wc_AesEncrypt(Aes *aes, const byte *inBlock, byte *outBlock);

#if defined(HAVE_AES_DECRYPT)
WOLFSSL_API int wc_AesDecrypt(Aes *aes, const byte *inBlock, byte *outBlock);
#endif

#endif

#if defined(HAVE_PK_CALLBACKS) &&  !defined(WOLFSSL_PSA_NO_PKCB)

struct psa_ssl_ctx {
    psa_key_id_t private_key;
    psa_key_id_t dh_key;
};

WOLFSSL_API int wolfSSL_CTX_psa_enable(WOLFSSL_CTX *ctx);
WOLFSSL_API int wolfSSL_set_psa_ctx(WOLFSSL *ssl, struct psa_ssl_ctx *ctx);
WOLFSSL_API void wolfSSL_free_psa_ctx(struct psa_ssl_ctx *ctx);
WOLFSSL_API int wolfSSL_psa_set_private_key_id(struct psa_ssl_ctx *ctx,
                                               psa_key_id_t id);
#endif

#endif /* WOLFSSL_HAVE_PSA */
#endif /* WOLFSSL_PSA_H */
