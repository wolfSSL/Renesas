/* ext_mlkem.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef EXT_KYBER_H
#define EXT_KYBER_H

#ifdef WOLF_CRYPTO_CB
    #include <wolfssl/wolfcrypt/cryptocb.h>
#endif

#ifdef WOLFSSL_HAVE_MLKEM
#include <wolfssl/wolfcrypt/mlkem.h>

#if !defined(HAVE_LIBOQS)
#error "This code requires liboqs"
#endif

#if defined(WOLFSSL_WC_MLKEM)
#error "This code is incompatible with wolfCrypt's implementation of Kyber."
#endif

#if defined (HAVE_LIBOQS)
    #include <oqs/kem.h>

    #ifndef WOLFSSL_NO_ML_KEM
        #define EXT_KYBER_MAX_PRIV_SZ OQS_KEM_ml_kem_1024_length_secret_key
        #define EXT_KYBER_MAX_PUB_SZ  OQS_KEM_ml_kem_1024_length_public_key
    #elif defined(WOLFSSL_MLKEM_KYBER)
        #define EXT_KYBER_MAX_PRIV_SZ OQS_KEM_kyber_1024_length_secret_key
        #define EXT_KYBER_MAX_PUB_SZ  OQS_KEM_kyber_1024_length_public_key
    #endif
#endif

struct KyberKey {
    /* Type of key: KYBER_LEVEL1
     *              KYBER_LEVEL3
     *              KYBER_LEVEL5
     *
     * Note we don't save the variant (SHAKE vs AES) as that is decided at
     * configuration time. */
    int type;

#ifdef WOLF_CRYPTO_CB
    void* devCtx;
    int   devId;
#endif

    byte priv[EXT_KYBER_MAX_PRIV_SZ];
    byte pub[EXT_KYBER_MAX_PUB_SZ];
};

#if defined (HAVE_LIBOQS)
WOLFSSL_LOCAL int ext_mlkem_enabled(int id);
#endif
#endif /* WOLFSSL_HAVE_MLKEM */
#endif /* EXT_KYBER_H */
