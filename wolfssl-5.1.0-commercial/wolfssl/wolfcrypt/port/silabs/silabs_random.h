/* silabs_random.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef _SILABS_RANDOM_H_
#define _SILABS_RANDOM_H_


#if defined(WOLFSSL_SILABS_SE_ACCEL)

#include <wolfssl/wolfcrypt/types.h>

int silabs_GenerateRand(byte* output, word32 sz);

#endif /* WOLFSSL_SILABS_SE_ACCEL */

#endif /* _SILABS_RANDOM_H_ */
