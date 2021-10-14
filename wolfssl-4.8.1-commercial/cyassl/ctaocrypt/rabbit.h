/* rabbit.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifndef NO_RABBIT

#ifndef CTAO_CRYPT_RABBIT_H
#define CTAO_CRYPT_RABBIT_H

#include <wolfssl/wolfcrypt/rabbit.h>

/* for rabbit reverse compatibility */
#ifndef NO_RABBIT
    #define RabbitProcess wc_RabbitProcess
    #define RabbitSetKey  wc_RabbitSetKey
#endif

#endif /* CTAO_CRYPT_RABBIT_H */

#endif /* NO_RABBIT */

