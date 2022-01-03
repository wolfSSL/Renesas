/* md5.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef NO_MD5

#ifndef CTAO_CRYPT_MD5_H
#define CTAO_CRYPT_MD5_H

#include <wolfssl/wolfcrypt/md5.h>

#ifndef HAVE_FIPS
    #define InitMd5   wc_InitMd5
    #define Md5Update wc_Md5Update
    #define Md5Final  wc_Md5Final
    #define Md5Hash   wc_Md5Hash
#else
    /* redfined name so that hmac is calling same function names with fips */
    #define wc_InitMd5   InitMd5
    #define wc_Md5Update Md5Update
    #define wc_Md5Final  Md5Final
    #define wc_Md5Hash   Md5Hash
#endif

#endif /* CTAO_CRYPT_MD5_H */
#endif /* NO_MD5 */

