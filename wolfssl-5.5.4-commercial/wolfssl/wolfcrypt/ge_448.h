/* ge_448.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLF_CRYPT_GE_448_H
#define WOLF_CRYPT_GE_448_H

#include <wolfssl/wolfcrypt/settings.h>

#ifdef HAVE_ED448

#include <wolfssl/wolfcrypt/fe_448.h>

/*
ge448 means group element.

Here the group is the set of pairs (x,y) of field elements (see fe.h)
satisfying -x^2 + y^2 = 1 + d x^2y^2
where d = -39081.

Representations:
  ge448_p2 (projective) : (X:Y:Z) satisfying x=X/Z, y=Y/Z
  ge448_precomp (affine): (x,y)
*/

#ifdef ED448_SMALL
    typedef byte     ge448;
    #define GE448_WORDS    56
#elif defined(CURVED448_128BIT)
    typedef sword64  ge448;
    #define GE448_WORDS    8
#else
    typedef sword32  ge448;
    #define GE448_WORDS    16
#endif

typedef struct {
  ge448 X[GE448_WORDS];
  ge448 Y[GE448_WORDS];
  ge448 Z[GE448_WORDS];
} ge448_p2;


WOLFSSL_LOCAL int  ge448_compress_key(byte* out, const byte* xIn, const byte* yIn);
WOLFSSL_LOCAL int  ge448_from_bytes_negate_vartime(ge448_p2 *r, const byte *b);

WOLFSSL_LOCAL int  ge448_double_scalarmult_vartime(ge448_p2 *r, const byte *a,
                                    const ge448_p2 *A, const byte *b);
WOLFSSL_LOCAL void ge448_scalarmult_base(ge448_p2* h, const byte* a);
WOLFSSL_LOCAL void sc448_reduce(byte* b);
WOLFSSL_LOCAL void sc448_muladd(byte* r, const byte* a, const byte* b, const byte* d);
WOLFSSL_LOCAL void ge448_to_bytes(byte *s, const ge448_p2 *h);


#ifndef ED448_SMALL
typedef struct {
  ge448 x[GE448_WORDS];
  ge448 y[GE448_WORDS];
} ge448_precomp;

#endif /* !ED448_SMALL */

#endif /* HAVE_ED448 */

#endif /* WOLF_CRYPT_GE_448_H */
