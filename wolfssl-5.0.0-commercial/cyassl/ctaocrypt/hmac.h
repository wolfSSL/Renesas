/* hmac.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifndef NO_HMAC

#ifndef CTAO_CRYPT_HMAC_H
#define CTAO_CRYPT_HMAC_H

#include <wolfssl/wolfcrypt/hmac.h>
#define HmacSetKey wc_HmacSetKey
#define HmacUpdate wc_HmacUpdate
#define HmacFinal  wc_HmacFinal
#ifdef WOLFSSL_ASYNC_CRYPT
    #define HmacAsyncInit wc_HmacAsyncInit
    #define HmacAsyncFree wc_HmacAsyncFree
#endif
#define CyaSSL_GetHmacMaxSize wolfSSL_GetHmacMaxSize
#ifdef HAVE_HKDF
    #define HKDF wc_HKDF
#endif /* HAVE_HKDF */

#endif /* CTAO_CRYPT_HMAC_H */

#endif /* NO_HMAC */

