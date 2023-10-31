/* ext_xmss.h
 *
 * Copyright (C) 2006-2023 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef EXT_XMSS_H
#define EXT_XMSS_H

#ifdef WOLFSSL_HAVE_XMSS
#include <wolfssl/wolfcrypt/xmss.h>

#if !defined(HAVE_LIBXMSS)
    #error "This code requires libxmss"
#endif

#include <xmss.h>
#include <params.h>

#if defined(WOLFSSL_WC_XMSS)
    #error "This code is incompatible with wolfCrypt's implementation of XMSS."
#endif

struct XmssKey {
    unsigned char        pk[XMSS_SHA256_PUBLEN];
    uint32_t             oid;
    int                  is_xmssmt;
    xmss_params          params;
#ifndef WOLFSSL_XMSS_VERIFY_ONLY
    /* The secret key length is a function of xmss_params. */
    unsigned char *      sk;
    word32               sk_len;
    write_private_key_cb write_private_key; /* Callback to write/update key. */
    read_private_key_cb  read_private_key;  /* Callback to read key. */
    void *               context;           /* Context arg passed to callbacks. */
#endif /* ifndef WOLFSSL_XMSS_VERIFY_ONLY */
    enum wc_XmssState    state;
};

#endif /* WOLFSSL_HAVE_XMSS */
#endif /* EXT_XMSS_H */
