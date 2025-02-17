/* pwdbased.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/*!
    \file wolfssl/wolfcrypt/pwdbased.h
*/

#ifndef WOLF_CRYPT_PWDBASED_H
#define WOLF_CRYPT_PWDBASED_H

#include <wolfssl/wolfcrypt/types.h>

#ifndef NO_PWDBASED


#ifdef __cplusplus
    extern "C" {
#endif

#if FIPS_VERSION3_GE(6,0,0)
    extern const unsigned int wolfCrypt_FIPS_pbkdf_ro_sanity[2];
    WOLFSSL_LOCAL int wolfCrypt_FIPS_PBKDF_sanity(void);
#endif
/*
 * hashType renamed to typeH to avoid shadowing global declaration here:
 * wolfssl/wolfcrypt/asn.h line 173 in enum Oid_Types
 */
WOLFSSL_API int wc_PBKDF1_ex(byte* key, int keyLen, byte* iv, int ivLen,
                      const byte* passwd, int passwdLen,
                      const byte* salt, int saltLen, int iterations,
                      int hashType, void* heap);
WOLFSSL_API int wc_PBKDF1(byte* output, const byte* passwd, int pLen,
                      const byte* salt, int sLen, int iterations, int kLen,
                      int typeH);
WOLFSSL_API int wc_PBKDF2_ex(byte* output, const byte* passwd, int pLen,
                    const byte* salt, int sLen, int iterations, int kLen,
                    int typeH, void* heap, int devId);
WOLFSSL_API int wc_PBKDF2(byte* output, const byte* passwd, int pLen,
                      const byte* salt, int sLen, int iterations, int kLen,
                      int typeH);
WOLFSSL_API int wc_PKCS12_PBKDF(byte* output, const byte* passwd, int pLen,
                            const byte* salt, int sLen, int iterations,
                            int kLen, int typeH, int purpose);
WOLFSSL_API int wc_PKCS12_PBKDF_ex(byte* output, const byte* passwd,int passLen,
                       const byte* salt, int saltLen, int iterations, int kLen,
                       int hashType, int id, void* heap);

#ifdef HAVE_SCRYPT
WOLFSSL_API int wc_scrypt(byte* output, const byte* passwd, int passLen,
                          const byte* salt, int saltLen, int cost,
                          int blockSize, int parallel, int dkLen);
WOLFSSL_API int wc_scrypt_ex(byte* output, const byte* passwd, int passLen,
                             const byte* salt, int saltLen, word32 iterations,
                             int blockSize, int parallel, int dkLen);
#endif


#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* NO_PWDBASED */
#endif /* WOLF_CRYPT_PWDBASED_H */
