/* error-crypt.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifndef CTAO_CRYPT_ERROR_H
#define CTAO_CRYPT_ERROR_H

/* for name change and fips compatibility @wc_fips */
#include <wolfssl/wolfcrypt/error-crypt.h>
#define CTaoCryptErrorString    wc_ErrorString
#define CTaoCryptGetErrorString wc_GetErrorString

#endif /* CTAO_CRYPT_ERROR_H */

