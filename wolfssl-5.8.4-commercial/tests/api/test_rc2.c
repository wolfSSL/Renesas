/* test_rc2.c
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

#include <wolfssl/wolfcrypt/rc2.h>
#include <wolfssl/wolfcrypt/types.h>
#include <tests/api/api.h>
#include <tests/api/test_rc2.h>

/*
 * Testing function for wc_Rc2SetKey().
 */
int test_wc_Rc2SetKey(void)
{
    EXPECT_DECLS;
#ifdef WC_RC2
    Rc2  rc2;
    byte key40[] = { 0x01, 0x02, 0x03, 0x04, 0x05 };
    byte iv[]    = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };

    /* valid key and IV */
    ExpectIntEQ(wc_Rc2SetKey(&rc2, key40, (word32) sizeof(key40) / sizeof(byte),
        iv, 40), 0);
    /* valid key, no IV */
    ExpectIntEQ(wc_Rc2SetKey(&rc2, key40, (word32) sizeof(key40) / sizeof(byte),
        NULL, 40), 0);

    /* bad arguments  */
    /* null Rc2 struct */
    ExpectIntEQ(wc_Rc2SetKey(NULL, key40, (word32) sizeof(key40) / sizeof(byte),
        iv, 40), WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    /* null key */
    ExpectIntEQ(wc_Rc2SetKey(&rc2, NULL, (word32) sizeof(key40) / sizeof(byte),
        iv, 40), WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    /* key size == 0 */
    ExpectIntEQ(wc_Rc2SetKey(&rc2, key40, 0, iv, 40),
        WC_NO_ERR_TRACE(WC_KEY_SIZE_E));
    /* key size > 128 */
    ExpectIntEQ(wc_Rc2SetKey(&rc2, key40, 129, iv, 40),
        WC_NO_ERR_TRACE(WC_KEY_SIZE_E));
    /* effective bits == 0 */
    ExpectIntEQ(wc_Rc2SetKey(&rc2, key40, (word32)sizeof(key40) / sizeof(byte),
        iv, 0), WC_NO_ERR_TRACE(WC_KEY_SIZE_E));
    /* effective bits > 1024 */
    ExpectIntEQ(wc_Rc2SetKey(&rc2, key40, (word32)sizeof(key40) / sizeof(byte),
        iv, 1025), WC_NO_ERR_TRACE(WC_KEY_SIZE_E));
#endif
    return EXPECT_RESULT();
} /* END test_wc_Rc2SetKey */

/*
 * Testing function for wc_Rc2SetIV().
 */
int test_wc_Rc2SetIV(void)
{
    EXPECT_DECLS;
#ifdef WC_RC2
    Rc2  rc2;
    byte iv[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };

    /* valid IV */
    ExpectIntEQ(wc_Rc2SetIV(&rc2, iv), 0);
    /* valid NULL IV */
    ExpectIntEQ(wc_Rc2SetIV(&rc2, NULL), 0);

    /* bad arguments */
    ExpectIntEQ(wc_Rc2SetIV(NULL, iv), WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    ExpectIntEQ(wc_Rc2SetIV(NULL, NULL), WC_NO_ERR_TRACE(BAD_FUNC_ARG));
#endif
    return EXPECT_RESULT();
} /* END test_wc_Rc2SetIV */

/*
 * Testing function for wc_Rc2EcbEncrypt() and wc_Rc2EcbDecrypt().
 */
int test_wc_Rc2EcbEncryptDecrypt(void)
{
    EXPECT_DECLS;
#ifdef WC_RC2
    Rc2 rc2;
    int effectiveKeyBits = 63;
    byte cipher[RC2_BLOCK_SIZE];
    byte plain[RC2_BLOCK_SIZE];
    byte key[]    = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    byte input[]  = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    byte output[] = { 0xeb, 0xb7, 0x73, 0xf9, 0x93, 0x27, 0x8e, 0xff };

    XMEMSET(cipher, 0, sizeof(cipher));
    XMEMSET(plain, 0, sizeof(plain));

    ExpectIntEQ(wc_Rc2SetKey(&rc2, key, (word32) sizeof(key) / sizeof(byte),
        NULL, effectiveKeyBits), 0);
    ExpectIntEQ(wc_Rc2EcbEncrypt(&rc2, cipher, input, RC2_BLOCK_SIZE), 0);
    ExpectIntEQ(XMEMCMP(cipher, output, RC2_BLOCK_SIZE), 0);

    ExpectIntEQ(wc_Rc2EcbDecrypt(&rc2, plain, cipher, RC2_BLOCK_SIZE), 0);
    ExpectIntEQ(XMEMCMP(plain, input, RC2_BLOCK_SIZE), 0);

    /* Rc2EcbEncrypt bad arguments */
    /* null Rc2 struct */
    ExpectIntEQ(wc_Rc2EcbEncrypt(NULL, cipher, input, RC2_BLOCK_SIZE),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    /* null out buffer */
    ExpectIntEQ(wc_Rc2EcbEncrypt(&rc2, NULL, input, RC2_BLOCK_SIZE),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    /* null input buffer */
    ExpectIntEQ(wc_Rc2EcbEncrypt(&rc2, cipher, NULL, RC2_BLOCK_SIZE),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    /* output buffer sz != RC2_BLOCK_SIZE (8) */
    ExpectIntEQ(wc_Rc2EcbEncrypt(&rc2, cipher, input, 7),
        WC_NO_ERR_TRACE(BUFFER_E));

    /* Rc2EcbDecrypt bad arguments */
    /* null Rc2 struct */
    ExpectIntEQ(wc_Rc2EcbDecrypt(NULL, plain, output, RC2_BLOCK_SIZE),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    /* null out buffer */
    ExpectIntEQ(wc_Rc2EcbDecrypt(&rc2, NULL, output, RC2_BLOCK_SIZE),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    /* null input buffer */
    ExpectIntEQ(wc_Rc2EcbDecrypt(&rc2, plain, NULL, RC2_BLOCK_SIZE),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    /* output buffer sz != RC2_BLOCK_SIZE (8) */
    ExpectIntEQ(wc_Rc2EcbDecrypt(&rc2, plain, output, 7),
        WC_NO_ERR_TRACE(BUFFER_E));
#endif
    return EXPECT_RESULT();
} /* END test_wc_Rc2EcbEncryptDecrypt */

/*
 * Testing function for wc_Rc2CbcEncrypt() and wc_Rc2CbcDecrypt().
 */
int test_wc_Rc2CbcEncryptDecrypt(void)
{
    EXPECT_DECLS;
#ifdef WC_RC2
    Rc2 rc2;
    int effectiveKeyBits = 63;
    byte cipher[RC2_BLOCK_SIZE*2];
    byte plain[RC2_BLOCK_SIZE*2];
    /* vector taken from test.c */
    byte key[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    byte iv[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    byte input[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    byte output[] = {
        0xeb, 0xb7, 0x73, 0xf9, 0x93, 0x27, 0x8e, 0xff,
        0xf0, 0x51, 0x77, 0x8b, 0x65, 0xdb, 0x13, 0x57
    };

    XMEMSET(cipher, 0, sizeof(cipher));
    XMEMSET(plain, 0, sizeof(plain));

    ExpectIntEQ(wc_Rc2SetKey(&rc2, key, (word32) sizeof(key) / sizeof(byte),
        iv, effectiveKeyBits), 0);
    ExpectIntEQ(wc_Rc2CbcEncrypt(&rc2, cipher, input, sizeof(input)), 0);
    ExpectIntEQ(XMEMCMP(cipher, output, sizeof(output)), 0);

    /* reset IV for decrypt */
    ExpectIntEQ(wc_Rc2SetIV(&rc2, iv), 0);
    ExpectIntEQ(wc_Rc2CbcDecrypt(&rc2, plain, cipher, sizeof(cipher)), 0);
    ExpectIntEQ(XMEMCMP(plain, input, sizeof(input)), 0);

    /* Rc2CbcEncrypt bad arguments */
    /* null Rc2 struct */
    ExpectIntEQ(wc_Rc2CbcEncrypt(NULL, cipher, input, sizeof(input)),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    /* null out buffer */
    ExpectIntEQ(wc_Rc2CbcEncrypt(&rc2, NULL, input, sizeof(input)),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    /* null input buffer */
    ExpectIntEQ(wc_Rc2CbcEncrypt(&rc2, cipher, NULL, sizeof(input)),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));

    /* Rc2CbcDecrypt bad arguments */
    /* in size is 0 */
    ExpectIntEQ(wc_Rc2CbcDecrypt(&rc2, plain, output, 0), 0);
    /* null Rc2 struct */
    ExpectIntEQ(wc_Rc2CbcDecrypt(NULL, plain, output, sizeof(output)),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    /* null out buffer */
    ExpectIntEQ(wc_Rc2CbcDecrypt(&rc2, NULL, output, sizeof(output)),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    /* null input buffer */
    ExpectIntEQ(wc_Rc2CbcDecrypt(&rc2, plain, NULL, sizeof(output)),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
#endif
    return EXPECT_RESULT();
} /* END test_wc_Rc2CbcEncryptDecrypt */

