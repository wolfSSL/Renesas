/* hc128.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifndef NO_HC128

#ifndef CTAO_CRYPT_HC128_H
#define CTAO_CRYPT_HC128_H

#include <wolfssl/wolfcrypt/hc128.h>

/* for hc128 reverse compatibility */
#ifdef HAVE_HC128
    #define Hc128_Process wc_Hc128_Process
    #define Hc128_SetKey  wc_Hc128_SetKey
#endif

#endif /* CTAO_CRYPT_HC128_H */

#endif /* HAVE_HC128 */

