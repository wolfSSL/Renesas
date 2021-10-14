/* ripemd.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */




#ifndef CTAO_CRYPT_RIPEMD_H
#define CTAO_CRYPT_RIPEME_H

#include <wolfssl/wolfcrypt/ripemd.h>

/* for ripemd reverse compatibility */
#ifdef WOLFSSL_RIPEMD
    #define InitRipeMd   wc_InitRipeMd
    #define RipeMdUpdate wc_RipeMdUpdate
    #define RipeMdFinal  wc_RipeMdFinal
#endif

#endif /* CTAO_CRYPT_RIPEMD_H */

