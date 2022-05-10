/* siphash.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLF_CRYPT_SIPHASH_H
#define WOLF_CRYPT_SIPHASH_H

#include <wolfssl/wolfcrypt/types.h>

#if defined(WOLFSSL_SIPHASH)

/* DESCRIPTION
 *
 * SipHash is a PseudoRandom Function (PRF) that can be used with small
 * messages (less than 256 bytes).
 * SipHash can be used for Message Authentication Codes (MACs) and as such must
 * be passed a secret key.
 * https://eprint.iacr.org/2012/351.pdf
 *
 * SipHash is commonly used in hash tables.
 * Do not use this as a hash not as a general purpose MAC.
 *
 * WOLFSSL_SIPHASH_CROUNDS and WOLFSSL_SIPHASH_DROUNDS can be defined at build
 * time to change the algorithm.
 * Default is SipHash-2-4:
 *   WOLFSSL_SIPHASH_CROUNDS = 2
 *   WOLFSSL_SIPHASH_DROUNDS = 4
 */

#ifndef WOLFSSL_SIPHASH_CROUNDS
/* Number of rounds to perform in compression operation. */
#define WOLFSSL_SIPHASH_CROUNDS  2
#endif /* WOLFSSL_SIPHASH_CROUNDS */

#ifndef WOLFSSL_SIPHASH_DROUNDS
/* Number of rounds to perform in final operation. */
#define WOLFSSL_SIPHASH_DROUNDS  4
#endif /* WOLFSSL_SIPHASH_DROUNDS */

enum {
    SIPHASH_KEY_SIZE    = 16,   /* Key size of SipHash. */
    SIPHASH_BLOCK_SIZE  = 8,    /* Block size of SipHash. */
    SIPHASH_MAC_SIZE_8  = 8,    /* Output an 8 byte MAC. */
    SIPHASH_MAC_SIZE_16 = 16,   /* Output a 16 byte MAC. */
};

typedef struct SipHash SipHash;

struct SipHash {
    /* Internal state. */
    word64 v[4];
    /* Cached message data. */
    byte cache[SIPHASH_BLOCK_SIZE];
    /* Number of bytes cached. */
    byte cacheCnt;
    /* Number of output bytes. */
    byte outSz;
    /* Number of input bytes processed. */
    word32 inCnt;
};


#ifdef __cplusplus
    extern "C" {
#endif

WOLFSSL_API int wc_InitSipHash(SipHash* sipHash, const unsigned char* key,
    unsigned char outSz);
WOLFSSL_API int wc_SipHashUpdate(SipHash* sipHash, const unsigned char* in,
    word32 inSz);
WOLFSSL_API int wc_SipHashFinal(SipHash* sipHash, unsigned char* out,
    unsigned char outSz);
WOLFSSL_API int wc_SipHash(const unsigned char* key, const unsigned char* in,
    word32 inSz, unsigned char* out, unsigned char outSz);

#ifdef __cplusplus
    } /* extern "C" */
#endif


#endif /* NO_AES && WOLFSSL_SIPHASH */
#endif /* WOLF_CRYPT_SIPHASH_H */

