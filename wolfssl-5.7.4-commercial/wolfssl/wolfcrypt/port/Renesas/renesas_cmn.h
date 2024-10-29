/* renesas_cmn.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
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

#ifndef WOLFSSL_RENESAS_TSIP_CRYPTONLY
#include <wolfssl/internal.h>


/* Common Callbacks */
WOLFSSL_LOCAL int Renesas_cmn_RsaSignCb(WOLFSSL* ssl,
                                const unsigned char* in, unsigned int inSz,
                                unsigned char* out, word32* outSz,
                                const unsigned char* keyDer, unsigned int keySz,
                                void* ctx);
WOLFSSL_LOCAL int Renesas_cmn_EccSignCb(WOLFSSL* ssl,
                                const unsigned char* in, unsigned int inSz,
                                unsigned char* out, word32* outSz,
                                const unsigned char* keyDer, unsigned int keySz,
                                void* ctx);
WOLFSSL_LOCAL int Renesas_cmn_genMasterSecret(WOLFSSL* ssl, void* ctx);
WOLFSSL_LOCAL int Renesas_cmn_generatePremasterSecret(WOLFSSL* ssl,
                                byte *premaster, word32 preSz, void* ctx);
WOLFSSL_LOCAL int Renesas_cmn_RsaEnc(WOLFSSL* ssl, const unsigned char* in,
       unsigned int inSz, unsigned char* out, word32* outSz,
       const unsigned char* keyDer, unsigned int keySz, void* ctx);
WOLFSSL_LOCAL int Renesas_cmn_VerifyHmac(WOLFSSL *ssl, const byte* message,
                    word32 messageSz, word32 macSz, word32 content, void* ctx);
WOLFSSL_LOCAL int Renesas_cmn_EccVerify(WOLFSSL* ssl, const unsigned char* sig,
        unsigned int sigSz, const unsigned char* hash, unsigned int hashSz,
        const unsigned char* key, unsigned int keySz, int* result, void* ctx);
WOLFSSL_LOCAL int Renesas_cmn_RsaVerify(WOLFSSL* ssl,
                                unsigned char* sig, unsigned int sigSz,
                                unsigned char** out, const unsigned char* key,
                                unsigned int keySz, void* ctx);
WOLFSSL_LOCAL int Renesas_cmn_RsaSignCheckCb(WOLFSSL* ssl,
                                unsigned char* sig, unsigned int sigSz,
                                unsigned char** out,
                                const unsigned char* keyDer, unsigned int keySz,
                                void* ctx);

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
WOLFSSL_LOCAL void* Renesas_cmn_GetCbCtxBydevId(int devId);
int wc_Renesas_cmn_RootCertVerify(const byte* cert, word32 cert_len,
        word32 key_n_start, word32 key_n_len, word32 key_e_start,
        word32 key_e_len, word32 cm_row);
WOLFSSL_LOCAL int Renesas_cmn_Cleanup(WOLFSSL* ssl);
WOLFSSL_LOCAL byte Renesas_cmn_checkCA(word32 cmIdx);
WOLFSSL_LOCAL int Renesas_cmn_TlsFinished(WOLFSSL* ssl, const byte *side,
                            const byte *handshake_hash, word32 hashSz,
                            byte *hashes, void* ctx);
WOLFSSL_LOCAL int Renesas_cmn_generateSessionKey(WOLFSSL* ssl, void* ctx);
#endif /* WOLFSSL_RENESAS_TSIP_CRYPTONLY */

int wc_CryptoCb_CryptInitRenesasCmn(struct WOLFSSL* ssl, void* ctx);
void wc_CryptoCb_CleanupRenesasCmn(int* id);

#endif /* __RENESAS_CMN_H__ */
