/* kcapi_hmac.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLF_CRYPT_KCAPI_HMAC_H
#define WOLF_CRYPT_KCAPI_HMAC_H

#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/port/kcapi/wc_kcapi.h>
#include <wolfssl/wolfcrypt/hmac.h>

#if defined(HAVE_FIPS) && \
                        (!defined(HAVE_FIPS_VERSION) || (HAVE_FIPS_VERSION < 2))
int HmacInit(Hmac* hmac, void* heap, int devId);
void HmacFree(Hmac* hmac);
#endif

#endif /* WOLF_CRYPT_KCAPI_HMAC_H  */

