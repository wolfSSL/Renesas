/* des3.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifndef NO_DES3

#ifndef CTAO_CRYPT_DES3_H
#define CTAO_CRYPT_DES3_H


#include <wolfssl/wolfcrypt/des3.h>
#define Des_SetKey     wc_Des_SetKey
#define Des_SetIV      wc_Des_SetIV
#define Des_CbcEncrypt wc_Des_CbcEncrypt
#define Des_CbcDecrypt wc_Des_CbcDecrypt
#define Des_EcbEncrypt wc_Des_EcbEncrypt
#define Des_CbcDecryptWithKey  wc_Des_CbcDecryptWithKey
#define Des3_SetKey            wc_Des3_SetKey
#define Des3_SetIV             wc_Des3_SetIV
#define Des3_CbcEncrypt        wc_Des3_CbcEncrypt
#define Des3_CbcDecrypt        wc_Des3_CbcDecrypt
#define Des3_CbcDecryptWithKey wc_Des3_CbcDecryptWithKey
#ifdef WOLFSSL_ASYNC_CRYPT
    #define Des3AsyncInit wc_Des3AsyncInit
    #define Des3AsyncFree wc_Des3AsyncFree
#endif

#endif /* NO_DES3 */
#endif /* CTAO_CRYPT_DES3_H */

