/* pico.c
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */




#include <inttypes.h>
#include <string.h>
#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/wolfcrypt/types.h>

#if defined(WOLFSSL_RPIPICO)
#include "pico/rand.h"


/* On RP2040 this uses an optimized PRNG, on RP2350 this uses a hardware TRNG.
 * There is a 128bit function, but internally this is just 2x 64bit calls.
 * Likewise the 32bit call is just a truncated 64bit call, so just stick with
 * the 64bit calls.
 */

int wc_pico_rng_gen_block(unsigned char *output, unsigned int sz)
{
    uint32_t i = 0;

    while (i < sz)
    {
        uint64_t rnd = get_rand_64();
        if (i + 8 < sz)
        {
            XMEMCPY(output + i, &rnd, 8);
            i += 8;
        } else {
            XMEMCPY(output + i, &rnd, sz - i);
            i = sz;
        }
    }

    return 0;
}
#endif
