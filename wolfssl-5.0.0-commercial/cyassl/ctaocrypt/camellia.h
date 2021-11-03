/* camellia.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef CTAO_CRYPT_CAMELLIA_H
#define CTAO_CRYPT_CAMELLIA_H


/* for camellia reverse compatibility */
#ifdef HAVE_CAMELLIA
    #include <wolfssl/wolfcrypt/camellia.h>
	#define CamelliaSetKey        wc_CamelliaSetKey
	#define CamelliaSetIV         wc_CamelliaSetIV
	#define CamelliaEncryptDirect wc_CamelliaEncryptDirect
	#define CamelliaDecryptDirect wc_CamelliaDecryptDirect
	#define CamelliaCbcEncrypt    wc_CamelliaCbcEncrypt
	#define CamelliaCbcDecrypt    wc_CamelliaCbcDecrypt
#endif

#endif /* CTAO_CRYPT_CAMELLIA_H */

