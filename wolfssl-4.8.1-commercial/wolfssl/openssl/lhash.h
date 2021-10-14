/* lhash.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* lhash.h for openSSL */

#ifndef WOLFSSL_lhash_H_
#define WOLFSSL_lhash_H_

#ifdef __cplusplus
    extern "C" {
#endif

#include <wolfssl/openssl/ssl.h>

#ifdef OPENSSL_ALL
#define IMPLEMENT_LHASH_HASH_FN(name, type) \
    unsigned long wolfSSL_##name##_LHASH_HASH(const void *arg) \
    {                                                          \
        const type *a = arg;                                 \
        return name##_hash(a);                                 \
    }
#define IMPLEMENT_LHASH_COMP_FN(name, type) \
    int wolfSSL_##name##_LHASH_COMP(const void *p1, const void *p2) \
    {                                                               \
        const type *_p1 = p1;                                       \
        const type *_p2 = p2;                                       \
        return name##_cmp(_p1, _p2);                                \
    }

#define LHASH_HASH_FN(name) wolfSSL_##name##_LHASH_HASH
#define LHASH_COMP_FN(name) wolfSSL_##name##_LHASH_COMP

WOLFSSL_API unsigned long wolfSSL_LH_strhash(const char *str);

WOLFSSL_API void *wolfSSL_lh_retrieve(WOLFSSL_STACK *sk, void *data);

#define lh_strhash          wolfSSL_LH_strhash

#endif


#ifdef  __cplusplus
} /* extern "C" */
#endif

#endif /* WOLFSSL_lhash_H_ */
