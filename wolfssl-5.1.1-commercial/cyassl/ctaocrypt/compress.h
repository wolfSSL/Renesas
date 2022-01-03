/* compress.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */



#ifdef HAVE_LIBZ

#ifndef CTAO_CRYPT_COMPRESS_H
#define CTAO_CRYPT_COMPRESS_H

#include <wolfssl/wolfcrypt/compress.h>

/* reverse compatibility */
#define Compress   wc_Compress
#define DeCompress wc_DeCompress

#endif /* CTAO_CRYPT_COMPRESS_H */

#endif /* HAVE_LIBZ */

