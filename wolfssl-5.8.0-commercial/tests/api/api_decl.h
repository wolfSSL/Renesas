/* api_decl.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_API_DECL_H
#define WOLFCRYPT_TEST_API_DECL_H

typedef int (*TEST_FUNC)(void);
typedef struct {
    const char *group;
    const char *name;
    TEST_FUNC func;
    byte run:1;
    byte fail:1;
} TEST_CASE;

#define TEST_DECL(func) { NULL, #func, func, 0, 0 }
#define TEST_DECL_GROUP(group, func) { group, #func, func, 0, 0 }

#endif /* WOLFCRYPT_TEST_API_DECL_H */

