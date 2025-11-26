/* test_poly1305.c
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include <tests/unit.h>

#ifdef NO_INLINE
    #include <wolfssl/wolfcrypt/misc.h>
#else
    #define WOLFSSL_MISC_INCLUDED
    #include <wolfcrypt/src/misc.c>
#endif

#include <wolfssl/wolfcrypt/poly1305.h>
#include <wolfssl/wolfcrypt/types.h>
#include <tests/api/api.h>
#include <tests/api/test_poly1305.h>

/*
 * unit test for wc_Poly1305SetKey()
 */
int test_wc_Poly1305SetKey(void)
{
    EXPECT_DECLS;
#ifdef HAVE_POLY1305
    Poly1305    ctx;
    const byte  key[] =
    {
         0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
         0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
         0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
         0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01
    };
    word32 keySz = (word32)(sizeof(key)/sizeof(byte));

    ExpectIntEQ(wc_Poly1305SetKey(&ctx, key, keySz), 0);

    /* Test bad args. */
    ExpectIntEQ(wc_Poly1305SetKey(NULL, key,keySz),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    ExpectIntEQ(wc_Poly1305SetKey(&ctx, NULL, keySz),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    ExpectIntEQ(wc_Poly1305SetKey(&ctx, key, 18),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
#endif
    return EXPECT_RESULT();
} /* END test_wc_Poly1305_SetKey() */

