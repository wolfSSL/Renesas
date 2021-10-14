/* chacha.h
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
This library contains implementation for the ChaCha20 stream cipher.

*/
/*!
    \file wolfssl/wolfcrypt/chacha.h
*/


#ifndef WOLF_CRYPT_CHACHA_H
#define WOLF_CRYPT_CHACHA_H

#include <wolfssl/wolfcrypt/types.h>

#ifdef HAVE_CHACHA

#ifdef __cplusplus
    extern "C" {
#endif

/*
Initialization vector starts at 13 with zero being the index origin of a matrix.
Block counter is located at index 12.
  0   1   2   3
  4   5   6   7
  8   9   10  11
  12  13  14  15
*/
#define CHACHA_MATRIX_CNT_IV 12

/* Size of the IV */
#define CHACHA_IV_WORDS    3

/* Size of IV in bytes*/
#define CHACHA_IV_BYTES 12
#ifdef HAVE_XCHACHA
#define XCHACHA_NONCE_BYTES 24
#endif

/* Size of ChaCha chunks */
#define CHACHA_CHUNK_WORDS 16
#define CHACHA_CHUNK_BYTES (CHACHA_CHUNK_WORDS * sizeof(word32))

#ifdef WOLFSSL_X86_64_BUILD
#if defined(USE_INTEL_SPEEDUP) && !defined(NO_CHACHA_ASM)
    #define USE_INTEL_CHACHA_SPEEDUP
    #define HAVE_INTEL_AVX1
#endif
#endif

enum {
	CHACHA_ENC_TYPE = WC_CIPHER_CHACHA,    /* cipher unique type */
    CHACHA_MAX_KEY_SZ = 32,
};

typedef struct ChaCha {
    word32 X[CHACHA_CHUNK_WORDS];           /* state of cipher */
#ifdef HAVE_INTEL_AVX1
    /* vpshufd reads 16 bytes but we only use bottom 4. */
    byte extra[12];
#endif
    word32 left;                            /* number of bytes leftover */
#if defined(USE_INTEL_CHACHA_SPEEDUP) || defined(WOLFSSL_ARMASM)
    word32 over[CHACHA_CHUNK_WORDS];
#endif
} ChaCha;

/**
  * IV(nonce) changes with each record
  * counter is for what value the block counter should start ... usually 0
  */
WOLFSSL_API int wc_Chacha_SetIV(ChaCha* ctx, const byte* inIv, word32 counter);

WOLFSSL_API int wc_Chacha_Process(ChaCha* ctx, byte* cipher, const byte* plain,
                              word32 msglen);

WOLFSSL_LOCAL void wc_Chacha_purge_current_block(ChaCha* ctx);

WOLFSSL_API int wc_Chacha_SetKey(ChaCha* ctx, const byte* key, word32 keySz);

#ifdef HAVE_XCHACHA
WOLFSSL_API int wc_XChacha_SetKey(ChaCha *ctx, const byte *key, word32 keySz,
				  const byte *nonce, word32 nonceSz,
				  word32 counter);
#endif

#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* HAVE_CHACHA */
#endif /* WOLF_CRYPT_CHACHA_H */

