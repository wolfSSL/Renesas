/* rand.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* rand.h for openSSL */

#ifndef WOLFSSL_RAND_COMPAT_H_
#define WOLFSSL_RAND_COMPAT_H_

#include <wolfssl/openssl/ssl.h>
#include <wolfssl/wolfcrypt/random.h>

#ifndef OPENSSL_COEXIST

typedef WOLFSSL_RAND_METHOD RAND_METHOD;

#define RAND_set_rand_method     wolfSSL_RAND_set_rand_method

#endif /* !OPENSSL_COEXIST */

#endif /* WOLFSSL_RAND_COMPAT_H_ */
