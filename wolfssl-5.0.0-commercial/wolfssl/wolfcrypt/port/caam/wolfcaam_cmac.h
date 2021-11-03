/* wolfcaam_cmac.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#include <wolfssl/wolfcrypt/settings.h>

#ifndef WOLFCAAM_CMAC_H
#define WOLFCAAM_CMAC_H

#if defined(WOLFSSL_CMAC) && defined(WOLFSSL_QNX_CAAM)

#include <wolfssl/wolfcrypt/cmac.h>

WOLFSSL_LOCAL int wc_CAAM_Cmac(Cmac* cmac, const byte* key, word32 keySz,
        const byte* in, word32 inSz, byte* out, word32* outSz, int type,
        void* ctx);
#endif
#endif /* WOLFCAAM_CMAC_H */
