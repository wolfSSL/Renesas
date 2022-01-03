/* silabs_hash.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef _SILABS_HASH_H_
#define _SILABS_HASH_H_

#include <em_device.h>

#if defined(WOLFSSL_SILABS_SE_ACCEL)

#include <wolfssl/wolfcrypt/types.h>

#include <sl_se_manager.h>
#include <sl_se_manager_hash.h>

#if defined(SL_SE_HASH_SHA384) && !defined(NO_SHA384)
#define WOLFSSL_SILABS_SHA384
#endif

#if defined(SL_SE_HASH_SHA512) && !defined(NO_SHA384)
#define WOLFSSL_SILABS_SHA512
#endif

typedef struct {
  sl_se_hash_streaming_context_t hash_ctx;
  sl_se_command_context_t cmd_ctx;
  union hash_type_ctx_u {
    sl_se_sha1_streaming_context_t   sha1_ctx;
    sl_se_sha224_streaming_context_t sha224_ctx;
    sl_se_sha256_streaming_context_t sha256_ctx;
#ifdef WOLFSSL_SILABS_SHA384
    sl_se_sha384_streaming_context_t sha384_ctx;
#endif
#ifdef WOLFSSL_SILABS_SHA512
    sl_se_sha512_streaming_context_t sha512_ctx;
#endif
  } hash_type_ctx;
} wc_silabs_sha_t;

int wc_silabs_se_hash_init (wc_silabs_sha_t* sha, enum wc_HashType type);
int wc_silabs_se_hash_update (wc_silabs_sha_t* sha, const byte* data, word32 len);
int wc_silabs_se_hash_final (wc_silabs_sha_t* sha, byte* hash);



#endif /* defined(WOLFSSL_SILABS_SE_ACCEL) */

#endif /* _SILABS_HASH_H_ */
