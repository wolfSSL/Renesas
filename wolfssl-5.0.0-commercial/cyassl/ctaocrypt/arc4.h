/* arc4.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef CTAO_CRYPT_ARC4_H
#define CTAO_CRYPT_ARC4_H

/* for arc4 reverse compatibility */
#ifndef NO_RC4
#include <wolfssl/wolfcrypt/arc4.h>
    #define Arc4Process wc_Arc4Process
    #define Arc4SetKey wc_Arc4SetKey
    #define Arc4AsyncInit wc_Arc4AsyncInit
    #define Arc4AsyncFree wc_Arc4AsyncFree
#endif

#endif /* CTAO_CRYPT_ARC4_H */

