/* random.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifndef CTAO_CRYPT_RANDOM_H
#define CTAO_CRYPT_RANDOM_H

    /* for random.h compatibility */
    #include <wolfssl/wolfcrypt/random.h>
    #define InitRng           wc_InitRng
    #define RNG_GenerateBlock wc_RNG_GenerateBlock
    #define RNG_GenerateByte  wc_RNG_GenerateByte
    #define FreeRng        wc_FreeRng

	#if defined(HAVE_HASHDRBG) || defined(NO_RC4)
	    #define RNG_HealthTest wc_RNG_HealthTest
	#endif /* HAVE_HASHDRBG || NO_RC4 */

#endif /* CTAO_CRYPT_RANDOM_H */

