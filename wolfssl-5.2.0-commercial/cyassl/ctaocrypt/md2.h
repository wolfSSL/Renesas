/* md2.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



/* check for old macro */
#if !defined(CYASSL_MD2) && defined(WOLFSSL_MD2)
    #define CYASSL_MD2
#endif

#ifdef CYASSL_MD2

#ifndef CTAO_CRYPT_MD2_H
#define CTAO_CRYPT_MD2_H

#include <wolfssl/wolfcrypt/md2.h>

#define InitMd2   wc_InitMd2
#define Md2Update wc_Md2Update
#define Md2Final  wc_Md2Final
#define Md2Hash   wc_Md2Hash

#endif /* CTAO_CRYPT_MD2_H */
#endif /* CYASSL_MD2 */

