/* sha.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifndef NO_SHA

#ifndef CTAO_CRYPT_SHA_H
#define CTAO_CRYPT_SHA_H

#include <wolfssl/wolfcrypt/sha.h>
#define InitSha   wc_InitSha
#define ShaUpdate wc_ShaUpdate
#define ShaFinal  wc_ShaFinal
#define ShaHash   wc_ShaHash

#endif /* CTAO_CRYPT_SHA_H */
#endif /* NO_SHA */

