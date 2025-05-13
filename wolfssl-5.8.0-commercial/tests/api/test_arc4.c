/* test_arc4.c
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

#include <wolfssl/wolfcrypt/arc4.h>
#include <wolfssl/wolfcrypt/types.h>
#include <tests/api/api.h>
#include <tests/api/test_arc4.h>

/*
 * Testing wc_Arc4SetKey()
 */
int test_wc_Arc4SetKey(void)
{
    EXPECT_DECLS;
#ifndef NO_RC4
    Arc4 arc;
    const char* key = "\x01\x23\x45\x67\x89\xab\xcd\xef";
    int keyLen = 8;

    ExpectIntEQ(wc_Arc4SetKey(&arc, (byte*)key, (word32)keyLen), 0);
    /* Test bad args. */
    ExpectIntEQ(wc_Arc4SetKey(NULL, (byte*)key, (word32)keyLen),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    ExpectIntEQ(wc_Arc4SetKey(&arc, NULL      , (word32)keyLen),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    ExpectIntEQ(wc_Arc4SetKey(&arc, (byte*)key, 0     ),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
#endif
    return EXPECT_RESULT();

} /* END test_wc_Arc4SetKey */

/*
 * Testing wc_Arc4Process for ENC/DEC.
 */
int test_wc_Arc4Process(void)
{
    EXPECT_DECLS;
#ifndef NO_RC4
    Arc4 enc;
    Arc4 dec;
    const char* key = "\x01\x23\x45\x67\x89\xab\xcd\xef";
    int keyLen = 8;
    const char* input = "\x01\x23\x45\x67\x89\xab\xcd\xef";
    byte cipher[8];
    byte plain[8];

    /* Init stack variables */
    XMEMSET(&enc, 0, sizeof(Arc4));
    XMEMSET(&dec, 0, sizeof(Arc4));
    XMEMSET(cipher, 0, sizeof(cipher));
    XMEMSET(plain, 0, sizeof(plain));

    /* Use for async. */
    ExpectIntEQ(wc_Arc4Init(&enc, NULL, INVALID_DEVID), 0);
    ExpectIntEQ(wc_Arc4Init(&dec, NULL, INVALID_DEVID), 0);

    ExpectIntEQ(wc_Arc4SetKey(&enc, (byte*)key, (word32)keyLen), 0);
    ExpectIntEQ(wc_Arc4SetKey(&dec, (byte*)key, (word32)keyLen), 0);

    ExpectIntEQ(wc_Arc4Process(&enc, cipher, (byte*)input, (word32)keyLen), 0);
    ExpectIntEQ(wc_Arc4Process(&dec, plain, cipher, (word32)keyLen), 0);
    ExpectIntEQ(XMEMCMP(plain, input, keyLen), 0);

    /* Bad args. */
    ExpectIntEQ(wc_Arc4Process(NULL, plain, cipher, (word32)keyLen),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    ExpectIntEQ(wc_Arc4Process(&dec, NULL, cipher, (word32)keyLen),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    ExpectIntEQ(wc_Arc4Process(&dec, plain, NULL, (word32)keyLen),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));

    wc_Arc4Free(&enc);
    wc_Arc4Free(&dec);
#endif
    return EXPECT_RESULT();

} /* END test_wc_Arc4Process */

