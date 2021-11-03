/* txt_db.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFSSL_TXT_DB_H_
#define WOLFSSL_TXT_DB_H_

#include <wolfssl/openssl/ssl.h>

#define WOLFSSL_TXT_DB_MAX_FIELDS 10

struct WOLFSSL_TXT_DB {
    int num_fields;
    WOLF_STACK_OF(WOLFSSL_STRING) *data;
    long error;
    long arg1;
    long arg2;
    wolf_sk_compare_cb comp[WOLFSSL_TXT_DB_MAX_FIELDS];
    wolf_sk_hash_cb hash_fn[WOLFSSL_TXT_DB_MAX_FIELDS];
};

typedef struct WOLFSSL_TXT_DB WOLFSSL_TXT_DB;

WOLFSSL_API WOLFSSL_TXT_DB *wolfSSL_TXT_DB_read(WOLFSSL_BIO *in, int num);
WOLFSSL_API long wolfSSL_TXT_DB_write(WOLFSSL_BIO  *out, WOLFSSL_TXT_DB *db);
WOLFSSL_API int wolfSSL_TXT_DB_insert(WOLFSSL_TXT_DB *db, WOLFSSL_STRING *row);
WOLFSSL_API void wolfSSL_TXT_DB_free(WOLFSSL_TXT_DB *db);
WOLFSSL_API int wolfSSL_TXT_DB_create_index(WOLFSSL_TXT_DB *db, int field,
        void* qual, wolf_sk_hash_cb hash, wolf_sk_compare_cb cmp);
WOLFSSL_API WOLFSSL_STRING *wolfSSL_TXT_DB_get_by_index(WOLFSSL_TXT_DB *db,
        int idx, WOLFSSL_STRING *value);

#define TXT_DB                  WOLFSSL_TXT_DB

#define TXT_DB_read             wolfSSL_TXT_DB_read
#define TXT_DB_write            wolfSSL_TXT_DB_write
#define TXT_DB_insert           wolfSSL_TXT_DB_insert
#define TXT_DB_free             wolfSSL_TXT_DB_free
#define TXT_DB_create_index     wolfSSL_TXT_DB_create_index
#define TXT_DB_get_by_index     wolfSSL_TXT_DB_get_by_index

#endif /* WOLFSSL_TXT_DB_H_ */
