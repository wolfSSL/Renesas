/* dcp_port.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
#ifndef _DCP_PORT_H_
#define _DCP_PORT_H_

#include <wolfssl/wolfcrypt/settings.h>
#include "fsl_dcp.h"

#ifndef NO_SHA256
#include <wolfssl/wolfcrypt/sha256.h>
void DCPSha256Free(wc_Sha256 *sha256);
#endif

#ifndef NO_SHA
#include <wolfssl/wolfcrypt/sha.h>
void DCPShaFree(wc_Sha *sha);
#endif

int wc_dcp_init(void);

#ifndef NO_AES
#include <wolfssl/wolfcrypt/aes.h>
int  DCPAesInit(Aes* aes);
void DCPAesFree(Aes *aes);

int  DCPAesSetKey(Aes* aes, const byte* key, word32 len, const byte* iv,
                          int dir);
int  DCPAesCbcEncrypt(Aes* aes, byte* out, const byte* in, word32 sz);
int  DCPAesCbcDecrypt(Aes* aes, byte* out, const byte* in, word32 sz);
#endif

#ifdef HAVE_AES_ECB
int  DCPAesEcbEncrypt(Aes* aes, byte* out, const byte* in, word32 sz);
int  DCPAesEcbDecrypt(Aes* aes, byte* out, const byte* in, word32 sz);
#endif


#endif
