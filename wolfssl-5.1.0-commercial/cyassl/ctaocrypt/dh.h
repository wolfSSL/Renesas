/* dh.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifndef NO_DH

#ifndef CTAO_CRYPT_DH_H
#define CTAO_CRYPT_DH_H

/* for dh reverse compatibility */
#include <wolfssl/wolfcrypt/dh.h>
#define InitDhKey         wc_InitDhKey
#define FreeDhKey         wc_FreeDhKey
#define DhGenerateKeyPair wc_DhGenerateKeyPair
#define DhAgree           wc_DhAgree
#define DhKeyDecode       wc_DhKeyDecode
#define DhSetKey          wc_DhSetKey
#define DhParamsLoad      wc_DhParamsLoad

#endif /* CTAO_CRYPT_DH_H */

#endif /* NO_DH */

