/* renesas_sync.h
 *
 * Copyright (C) 2006-2023 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef _RENESAS_SYNC_H_
#define _RENESAS_SYNC_H_

#ifdef HAVE_RENESAS_SYNC

struct WOLFSSL;
struct FSPSM_ST;
extern FSPSM_ST guser_PKCbInfo;

WOLFSSL_API int wc_CryptoCb_CryptInitRenesasCmn(struct WOLFSSL* ssl, void* ctx);
WOLFSSL_API void wc_CryptoCb_CleanupRenesasCmn(int* id);

#endif /* HAVE_RENESAS_SYNC */
#endif /* _RENESAS_SYNC_H_ */
