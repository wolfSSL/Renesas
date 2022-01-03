/* silabs_aes.c
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* Generic SILABS Series2 AES support Function */

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif


#include <wolfssl/wolfcrypt/settings.h>

#if defined(WOLFSSL_SILABS_SE_ACCEL)


#include <wolfssl/wolfcrypt/error-crypt.h>
#include <wolfssl/wolfcrypt/aes.h>
#include <wolfssl/wolfcrypt/port/silabs/silabs_aes.h>


int wc_AesSetKey(Aes* aes, const byte* userKey, word32 keylen,
                 const byte* iv, int dir)
{
    sl_se_command_context_t cc = SL_SE_COMMAND_CONTEXT_INIT;
    int ret = 0;
    (void)dir;

    ret = sl_se_init();
    if (ret != SL_STATUS_OK) {
        return BUFFER_E;
    }

    XMEMSET(aes, 0, sizeof(aes));

    if (keylen > sizeof(aes->key)) {
        return BAD_FUNC_ARG;
    }

    ret = wc_AesSetIV(aes, iv);
    aes->rounds = keylen/4 + 6;
    aes->ctx.cmd_ctx = cc;

    XMEMSET(&(aes->ctx.key), 0, sizeof(sl_se_key_descriptor_t));

    aes->ctx.key.storage.method = SL_SE_KEY_STORAGE_EXTERNAL_PLAINTEXT;
    switch(keylen) {
    case 128/8:
        aes->ctx.key.type = SL_SE_KEY_TYPE_AES_128;
        break;
#ifdef WOLFSSL_AES_192
    case 192/8:
        aes->ctx.key.type = SL_SE_KEY_TYPE_AES_192;
        break;
#endif
#ifdef WOLFSSL_AES_256
    case 256/8:
        aes->ctx.key.type = SL_SE_KEY_TYPE_AES_256;
        break;
#endif
    default:
        ret = BAD_FUNC_ARG;
        break;
    }


    XMEMCPY(aes->key, userKey, keylen);
    aes->ctx.key.storage.location.buffer.pointer = (void*)aes->key;
    aes->ctx.key.storage.location.buffer.size = keylen;
    aes->ctx.key.size = keylen;

    return ret;
}

int wc_AesCbcEncrypt(Aes* aes, byte* out, const byte* in, word32 sz)
{
    sl_status_t status = sl_se_aes_crypt_cbc(
        &(aes->ctx.cmd_ctx),
        &(aes->ctx.key),
        SL_SE_ENCRYPT,
        sz,
        (uint8_t*)aes->reg,
        in,
        out);
    return (status != SL_STATUS_OK) ? WC_HW_E : 0;
}

int wc_AesCbcDecrypt(Aes* aes, byte* out, const byte* in, word32 sz)
{
    sl_status_t status = sl_se_aes_crypt_cbc(
        &(aes->ctx.cmd_ctx),
        &(aes->ctx.key),
        SL_SE_DECRYPT,
        sz,
        (uint8_t*)aes->reg,
        in,
        out);
    return (status != SL_STATUS_OK) ? WC_HW_E : 0;
}

#ifdef HAVE_AESGCM
int wc_AesGcmEncrypt_silabs (Aes* aes, byte* out, const byte* in, word32 sz,
                            const byte* iv, word32 ivSz,
                            byte* authTag, word32 authTagSz,
                            const byte* authIn, word32 authInSz)
{
    sl_status_t status = sl_se_gcm_crypt_and_tag(
        &(aes->ctx.cmd_ctx),
        &(aes->ctx.key),
        SL_SE_ENCRYPT,
        sz,
        iv,
        ivSz,
        authIn,
        authInSz,
        in,
        out,
        authTagSz,
        authTag);

    return (status != SL_STATUS_OK) ? AES_GCM_AUTH_E : 0;
}

int wc_AesGcmDecrypt_silabs (Aes* aes, byte* out, const byte* in, word32 sz,
                            const byte* iv, word32 ivSz,
                            const byte* authTag, word32 authTagSz,
                            const byte* authIn, word32 authInSz)
{
    sl_status_t status = sl_se_gcm_auth_decrypt(
        &(aes->ctx.cmd_ctx),
        &(aes->ctx.key),
        sz,
        iv,
        ivSz,
        authIn,
        authInSz,
        in,
        out,
        authTagSz,
        (byte*)authTag);

    return (status != SL_STATUS_OK) ? AES_GCM_AUTH_E : 0;
}

#endif /* HAVE_AESGCM */


#ifdef HAVE_AESCCM
int wc_AesCcmEncrypt_silabs (Aes* aes, byte* out, const byte* in, word32 sz,
                             const byte* iv, word32 ivSz,
                             byte* authTag, word32 authTagSz,
                             const byte* authIn, word32 authInSz)
{
    sl_status_t status = sl_se_ccm_encrypt_and_tag(
        &(aes->ctx.cmd_ctx),
        &(aes->ctx.key),
        sz,
        iv,
        ivSz,
        authIn,
        authInSz,
        in,
        out,
        authTag,
        authTagSz
        );

    return (status != SL_STATUS_OK) ? AES_GCM_AUTH_E : 0;
}

int wc_AesCcmDecrypt_silabs (Aes* aes, byte* out, const byte* in, word32 sz,
                            const byte* iv, word32 ivSz,
                            const byte* authTag, word32 authTagSz,
                            const byte* authIn, word32 authInSz)
{
    sl_status_t status = sl_se_ccm_auth_decrypt(
        &(aes->ctx.cmd_ctx),
        &(aes->ctx.key),
        sz,
        iv,
        ivSz,
        authIn,
        authInSz,
        in,
        out,
        (byte*)authTag,
        authTagSz);

    return (status != SL_STATUS_OK) ? AES_GCM_AUTH_E : 0;
}

#endif /* HAVE_AESGCM */

#endif /* WOLFSSL_SILABS_SE_ACCEL */
