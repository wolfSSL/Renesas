/* poly1305.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifdef HAVE_POLY1305

#ifndef CTAO_CRYPT_POLY1305_H
#define CTAO_CRYPT_POLY1305_H

#include <wolfssl/wolfcrypt/poly1305.h>

/* for poly1305 reverse compatibility */
#define Poly1305SetKey wc_Poly1305SetKey
#define Poly1305Update wc_Poly1305Update
#define Poly1305Final  wc_Poly1305Final

#endif /* CTAO_CRYPT_POLY1305_H */

#endif /* HAVE_POLY1305 */

