/* test_dh.c
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

#include <wolfssl/wolfcrypt/dh.h>
#include <wolfssl/wolfcrypt/types.h>
#include <tests/api/api.h>
#include <tests/api/test_dh.h>

/*
 * Testing wc_DhPublicKeyDecode
 */
int test_wc_DhPublicKeyDecode(void)
{
    EXPECT_DECLS;
#ifndef NO_DH
#if defined(WOLFSSL_DH_EXTRA) && defined(USE_CERT_BUFFERS_2048)
    DhKey  key;
    word32 inOutIdx;

    XMEMSET(&key, 0, sizeof(DhKey));

    ExpectIntEQ(wc_InitDhKey(&key), 0);

    ExpectIntEQ(wc_DhPublicKeyDecode(NULL,NULL,NULL,0), WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    ExpectIntEQ(wc_DhPublicKeyDecode(dh_pub_key_der_2048,NULL,NULL,0),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    ExpectIntEQ(wc_DhPublicKeyDecode(dh_pub_key_der_2048,NULL,NULL,0),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    inOutIdx = 0;
    ExpectIntEQ(wc_DhPublicKeyDecode(dh_pub_key_der_2048,&inOutIdx,NULL, 0),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    inOutIdx = 0;
    ExpectIntEQ(wc_DhPublicKeyDecode(dh_pub_key_der_2048,&inOutIdx,&key, 0),
        WC_NO_ERR_TRACE(BAD_FUNC_ARG));
    inOutIdx = 0;
    ExpectIntEQ(wc_DhPublicKeyDecode(dh_pub_key_der_2048,&inOutIdx,&key,
        sizeof_dh_pub_key_der_2048), 0);
    ExpectIntNE(key.p.used, 0);
    ExpectIntNE(key.g.used, 0);
    ExpectIntEQ(key.q.used, 0);
    ExpectIntNE(key.pub.used, 0);
    ExpectIntEQ(key.priv.used, 0);

    DoExpectIntEQ(wc_FreeDhKey(&key), 0);
#endif
#endif /* !NO_DH */
    return EXPECT_RESULT();
}

