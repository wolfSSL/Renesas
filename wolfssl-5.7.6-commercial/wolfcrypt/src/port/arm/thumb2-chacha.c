/* thumb2-chacha.c
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wolfssl/wolfcrypt/settings.h>

#if defined(WOLFSSL_ARMASM) && defined(WOLFSSL_ARMASM_THUMB2)
#ifdef HAVE_CHACHA

#include <wolfssl/wolfcrypt/chacha.h>
#include <wolfssl/wolfcrypt/error-crypt.h>
#include <wolfssl/wolfcrypt/logging.h>
#include <wolfssl/wolfcrypt/cpuid.h>
#ifdef NO_INLINE
    #include <wolfssl/wolfcrypt/misc.h>
#else
    #define WOLFSSL_MISC_INCLUDED
    #include <wolfcrypt/src/misc.c>
#endif

#ifdef CHACHA_AEAD_TEST
    #include <stdio.h>
#endif

#ifdef CHACHA_TEST
    #include <stdio.h>
#endif


/* Set the Initialization Vector (IV) and counter into ChaCha context.
 *
 * Set up iv(nonce). Earlier versions used 64 bits instead of 96, this version
 * uses the typical AEAD 96 bit nonce and can do record sizes of 256 GB.
 *
 * @param [in] ctx      ChaCha context.
 * @param [in] iv       IV to set.
 * @param [in] counter  Starting value of counter.
 * @return  0 on success.
 * @return  BAD_FUNC_ARG when ctx or IV is NULL.
 */
int wc_Chacha_SetIV(ChaCha* ctx, const byte* iv, word32 counter)
{
    int ret = 0;
#ifdef CHACHA_AEAD_TEST
    word32 i;

    printf("NONCE : ");
    if (iv != NULL) {
        for (i = 0; i < CHACHA_IV_BYTES; i++) {
            printf("%02x", iv[i]);
        }
    }
    printf("\n\n");
#endif

    /* Validate parameters. */
    if ((ctx == NULL) || (iv == NULL)) {
        ret = BAD_FUNC_ARG;
    }
    if (ret == 0) {
        /* No unused bytes to XOR into input. */
        ctx->left = 0;

        /* Set counter and IV into state. */
        wc_chacha_setiv(ctx->X, iv, counter);
    }

    return ret;
}

/* Set the key into the ChaCha context.
 *
 * Key setup. 8 word iv (nonce)
 *
 * @param [in] ctx    ChaCha context.
 * @param [in] key    Key to set.
 * @param [in] keySz  Length of key in bytes. Valid values:
 *                        CHACHA_MAX_KEY_SZ and (CHACHA_MAX_KEY_SZ / 2)
 * @return  0 on success.
 * @return  BAD_FUNC_ARG when ctx or key is NULL.
 * @return  BAD_FUNC_ARG when keySz is invalid.
 */
int wc_Chacha_SetKey(ChaCha* ctx, const byte* key, word32 keySz)
{
    int ret = 0;

#ifdef CHACHA_AEAD_TEST
    printf("ChaCha key used :\n");
    if (key != NULL) {
        word32 i;
        for (i = 0; i < keySz; i++) {
            printf("%02x", key[i]);
            if ((i % 8) == 7)
               printf("\n");
        }
    }
    printf("\n\n");
#endif

    /* Validate parameters. */
    if ((ctx == NULL) || (key == NULL)) {
        ret = BAD_FUNC_ARG;
    }
    else if ((keySz != (CHACHA_MAX_KEY_SZ / 2)) &&
             (keySz !=  CHACHA_MAX_KEY_SZ     )) {
        ret = BAD_FUNC_ARG;
    }

    if (ret == 0) {
        ctx->left = 0;

        wc_chacha_setkey(ctx->X, key, keySz);
    }

    return ret;
}

/* API to encrypt/decrypt a message of any size.
 *
 * @param [in]  ctx     ChaCha context.
 * @param [out] output  Enciphered output.
 * @param [in]  input   Input to encipher.
 * @param [in]  len     Length of input in bytes.
 * @return  0 on success.
 * @return  BAD_FUNC_ARG when ctx, output or input is NULL.
 */
int wc_Chacha_Process(ChaCha* ctx, byte* output, const byte* input, word32 len)
{
    int ret = 0;

    if ((ctx == NULL) || (output == NULL) || (input == NULL)) {
        ret = BAD_FUNC_ARG;
    }

    /* Handle left over bytes from last block. */
    if ((ret == 0) && (len > 0) && (ctx->left > 0)) {
        byte* over = ((byte*)ctx->over) + CHACHA_CHUNK_BYTES - ctx->left;
        word32 l = min(len, ctx->left);

        wc_chacha_use_over(over, output, input, l);

        ctx->left -= l;
        input += l;
        output += l;
        len -= l;
    }

    if ((ret == 0) && (len != 0)) {
        wc_chacha_crypt_bytes(ctx, output, input, len);
    }

    return ret;
}

#endif /* HAVE_CHACHA */
#endif /* WOLFSSL_ARMASM && !WOLFSSL_ARMASM_NO_NEON */
