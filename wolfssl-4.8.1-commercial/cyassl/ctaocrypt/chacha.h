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


#ifndef CTAO_CRYPT_CHACHA_H
#define CTAO_CRYPT_CHACHA_H


/* for chacha reverse compatibility */
#ifdef HAVE_CHACHA
    #include <wolfssl/wolfcrypt/chacha.h>
    #define Chacha_Process wc_Chacha_Process
    #define Chacha_SetKey  wc_Chacha_SetKey
    #define Chacha_SetIV   wc_Chacha_SetIV
#endif

#endif /* CTAO_CRYPT_CHACHA_H */

