/* renesas_cmn.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
#ifndef __RENESAS_CMN_H__
#define __RENESAS_CMN_H__

#include <wolfssl/ssl.h>
#include <wolfssl/internal.h>

/* Common Callbacks */
WOLFSSL_LOCAL int Renesas_cmn_genMasterSecret(WOLFSSL* ssl, void* ctx);
WOLFSSL_LOCAL int Renesas_cmn_generatePremasterSecret(WOLFSSL* ssl, 
                                byte *premaster, word32 preSz, void* ctx);
WOLFSSL_LOCAL int Renesas_cmn_RsaEnc(WOLFSSL* ssl, const unsigned char* in, 
       unsigned int inSz, unsigned char* out, word32* outSz,
       const unsigned char* keyDer, unsigned int keySz, void* ctx);
WOLFSSL_LOCAL int Renesas_cmn_VerifyHmac(WOLFSSL *ssl, const byte* message, 
                    word32 messageSz, word32 macSz, word32 content, void* ctx);
WOLFSSL_LOCAL int Renesas_cmn_EccVerify(WOLFSSL* ssl, const uint8_t* sig, 
        uint32_t sigSz, const uint8_t* hash, uint32_t hashSz, 
        const uint8_t* key, uint32_t keySz, int* result, void* ctx);
WOLFSSL_LOCAL int Renesas_cmn_RsaVerify(WOLFSSL* ssl, byte* sig, uint32_t sigSz,
        uint8_t** out, const byte* key, uint32_t keySz, void* ctx);
WOLFSSL_LOCAL int Renesas_cmn_TLS_hmac(WOLFSSL* ssl, byte* digest, const byte* in,
             word32 sz, int padSz, int content, int verify, int epochOrder);
WOLFSSL_LOCAL int Renesas_cmn_usable(const WOLFSSL *ssl, byte seskey_gennerated);
WOLFSSL_LOCAL int Renesas_cmn_SigPkCbRsaVerify(unsigned char* sig, unsigned int sigSz,
       unsigned char** out, const unsigned char* keyDer, unsigned int keySz,
       void* ctx);
WOLFSSL_LOCAL int Renesas_cmn_SigPkCbEccVerify(const unsigned char* sig, unsigned int sigSz,
       const unsigned char* hash, unsigned int hashSz,
       const unsigned char* keyDer, unsigned int keySz,
       int* result, void* ctx);

/* Common Methods */
int wc_CryptoCb_CryptInitRenesasCmn(WOLFSSL* ssl, void* ctx);
void wc_CryptoCb_CleanupRenesasCmn(int* id);
int wc_Renesas_cmn_RootCertVerify(const byte* cert, word32 cert_len, 
        word32 key_n_start, word32 key_n_len, word32 key_e_start, 
        word32 key_e_len, word32 cm_row);
WOLFSSL_LOCAL byte Renesas_cmn_checkCA(word32 cmIdx);
#endif /* __RENESAS_CMN_H__ */