/* pkcs12.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLF_CRYPT_PKCS12_H
#define WOLF_CRYPT_PKCS12_H

#include <wolfssl/wolfcrypt/types.h>

#ifdef __cplusplus
    extern "C" {
#endif

typedef struct WC_PKCS12 WC_PKCS12;

typedef struct WC_DerCertList { /* dereferenced in ssl.c */
    byte* buffer;
    word32 bufferSz;
    struct WC_DerCertList* next;
} WC_DerCertList;

/* default values for creating PKCS12 */
enum {
    WC_PKCS12_ITT_DEFAULT = 2048,
    WC_PKCS12_VERSION_DEFAULT = 3,
    WC_PKCS12_MAC_DEFAULT = 1
};

WOLFSSL_API WC_PKCS12* wc_PKCS12_new(void);
WOLFSSL_API WC_PKCS12* wc_PKCS12_new_ex(void* heap);
WOLFSSL_API void wc_PKCS12_free(WC_PKCS12* pkcs12);
WOLFSSL_API int wc_d2i_PKCS12(const byte* der, word32 derSz, WC_PKCS12* pkcs12);
#ifndef NO_FILESYSTEM
WOLFSSL_API int wc_d2i_PKCS12_fp(const char* file, WC_PKCS12** pkcs12);
#endif
WOLFSSL_API int wc_i2d_PKCS12(WC_PKCS12* pkcs12, byte** der, int* derSz);
WOLFSSL_API int wc_PKCS12_parse(WC_PKCS12* pkcs12, const char* psw,
        byte** pkey, word32* pkeySz, byte** cert, word32* certSz,
        WC_DerCertList** ca);
WOLFSSL_LOCAL int wc_PKCS12_verify_ex(WC_PKCS12* pkcs12,
        const byte* psw, word32 pswSz);
WOLFSSL_API WC_PKCS12* wc_PKCS12_create(char* pass, word32 passSz,
        char* name, byte* key, word32 keySz, byte* cert, word32 certSz,
        WC_DerCertList* ca, int nidKey, int nidCert, int iter, int macIter,
        int keyType, void* heap);


WOLFSSL_LOCAL int wc_PKCS12_SetHeap(WC_PKCS12* pkcs12, void* heap);
WOLFSSL_LOCAL void* wc_PKCS12_GetHeap(WC_PKCS12* pkcs12);

WOLFSSL_API void wc_FreeCertList(WC_DerCertList* list, void* heap);

#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* WOLF_CRYPT_PKCS12_H */
