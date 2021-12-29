/* wolfcrypt/test/test.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef WOLFCRYPT_TEST_H
#define WOLFCRYPT_TEST_H


#ifdef __cplusplus
    extern "C" {
#endif

#ifdef HAVE_STACK_SIZE
THREAD_RETURN WOLFSSL_THREAD wolfcrypt_test(void* args);
#else
int wolfcrypt_test(void* args);
#endif

#ifdef __cplusplus
    }  /* extern "C" */
#endif


#endif /* WOLFCRYPT_TEST_H */

