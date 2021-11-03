/* pwdbased.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifndef NO_PWDBASED

#ifndef CTAO_CRYPT_PWDBASED_H
#define CTAO_CRYPT_PWDBASED_H

/* for pwdbased reverse compatibility */
#include <wolfssl/wolfcrypt/pwdbased.h>
#define PBKDF1       wc_PBKDF1
#define PBKDF2       wc_PBKDF2
#define PKCS12_PBKDF wc_PKCS12_PBKDF

#endif /* CTAO_CRYPT_PWDBASED_H */
#endif /* NO_PWDBASED */

