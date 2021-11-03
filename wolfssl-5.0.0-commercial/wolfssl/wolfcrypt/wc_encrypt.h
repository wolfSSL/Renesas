/* wc_encrypt.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/*!
    \file wolfssl/wolfcrypt/wc_encrypt.h
*/


#ifndef WOLF_CRYPT_ENCRYPT_H
#define WOLF_CRYPT_ENCRYPT_H

#include <wolfssl/wolfcrypt/types.h>
#ifndef NO_AES
    #include <wolfssl/wolfcrypt/aes.h>
#endif
#ifdef HAVE_CHACHA
    #include <wolfssl/wolfcrypt/chacha.h>
#endif
#ifndef NO_DES3
    #include <wolfssl/wolfcrypt/des3.h>
#endif
#ifndef NO_RC4
    #include <wolfssl/wolfcrypt/arc4.h>
#endif

#ifdef __cplusplus
    extern "C" {
#endif

/* determine max cipher key size - cannot use enum values here, must be define,
 * since WC_MAX_SYM_KEY_SIZE is used in if macro logic. */
#ifndef NO_AES
    #define WC_MAX_SYM_KEY_SIZE     (AES_MAX_KEY_SIZE/8)
#elif defined(HAVE_CHACHA)
    #define WC_MAX_SYM_KEY_SIZE     32 /* CHACHA_MAX_KEY_SZ */
#elif !defined(NO_DES3)
    #define WC_MAX_SYM_KEY_SIZE     24 /* DES3_KEY_SIZE */
#elif !defined(NO_RC4)
    #define WC_MAX_SYM_KEY_SIZE     16 /* RC4_KEY_SIZE */
#else
    #define WC_MAX_SYM_KEY_SIZE     32
#endif


#if (defined(HAVE_FIPS) && defined(HAVE_FIPS_VERSION) && \
     (HAVE_FIPS_VERSION <= 2)) || (defined(HAVE_SELFTEST) && \
     (!defined(HAVE_SELFTEST_VERSION) || (HAVE_SELFTEST_VERSION < 2)))
    /* In FIPS cert 3389 and CAVP selftest v1 build, these enums are
     * not in aes.h. Define them here outside the fips boundary. 
     */
    #ifndef GCM_NONCE_MID_SZ
        /* The usual default nonce size for AES-GCM. */
        #define GCM_NONCE_MID_SZ 12
    #endif
    #ifndef CCM_NONCE_MIN_SZ
        #define CCM_NONCE_MIN_SZ 7
    #endif
#endif


#if !defined(NO_AES) && defined(HAVE_AES_CBC)
WOLFSSL_API int wc_AesCbcEncryptWithKey(byte* out, const byte* in, word32 inSz,
                                        const byte* key, word32 keySz,
                                        const byte* iv);
WOLFSSL_API int wc_AesCbcDecryptWithKey(byte* out, const byte* in, word32 inSz,
                                        const byte* key, word32 keySz,
                                        const byte* iv);
#endif /* !NO_AES */


#ifndef NO_DES3
WOLFSSL_API int wc_Des_CbcDecryptWithKey(byte* out,
                                         const byte* in, word32 sz,
                                         const byte* key, const byte* iv);
WOLFSSL_API int wc_Des_CbcEncryptWithKey(byte* out,
                                         const byte* in, word32 sz,
                                         const byte* key, const byte* iv);
WOLFSSL_API int wc_Des3_CbcEncryptWithKey(byte* out,
                                          const byte* in, word32 sz,
                                          const byte* key, const byte* iv);
WOLFSSL_API int wc_Des3_CbcDecryptWithKey(byte* out,
                                          const byte* in, word32 sz,
                                          const byte* key, const byte* iv);
#endif /* !NO_DES3 */




#ifdef WOLFSSL_ENCRYPTED_KEYS
    struct EncryptedInfo;
    WOLFSSL_API int wc_BufferKeyDecrypt(struct EncryptedInfo* info, byte* der, word32 derSz,
        const byte* password, int passwordSz, int hashType);
    WOLFSSL_API int wc_BufferKeyEncrypt(struct EncryptedInfo* info, byte* der, word32 derSz,
        const byte* password, int passwordSz, int hashType);
#endif /* WOLFSSL_ENCRYPTED_KEYS */

#ifndef NO_PWDBASED
    WOLFSSL_LOCAL int wc_CryptKey(const char* password, int passwordSz, 
        byte* salt, int saltSz, int iterations, int id, byte* input, int length,
        int version, byte* cbcIv, int enc, int shaOid);
#endif

#ifdef __cplusplus
    }  /* extern "C" */
#endif

#endif /* WOLF_CRYPT_ENCRYPT_H */

