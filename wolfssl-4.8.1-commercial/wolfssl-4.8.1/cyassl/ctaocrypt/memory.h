/* memory.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


/* submitted by eof */


#ifndef CYASSL_MEMORY_H
#define CYASSL_MEMORY_H


#include <wolfssl/wolfcrypt/memory.h>
#define CyaSSL_Malloc_cb     wolfSSL_Malloc_cb
#define CyaSSL_Free_cb       wolfSSL_Free_cb
#define CyaSSL_Realloc_cb    wolfSSL_Realloc_cb
#define CyaSSL_SetAllocators wolfSSL_SetAllocators

/* Public in case user app wants to use XMALLOC/XFREE */
#define CyaSSL_Malloc  wolfSSL_Malloc
#define CyaSSL_Free    wolfSSL_Free
#define CyaSSL_Realloc wolfSSL_Realloc

#endif /* CYASSL_MEMORY_H */

