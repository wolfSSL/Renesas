/* ext_lms.h
 *
 * Copyright (C) 2006-2023 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef EXT_LMS_H
#define EXT_LMS_H

#ifdef WOLFSSL_HAVE_LMS
#include <wolfssl/wolfcrypt/lms.h>

#if !defined(HAVE_LIBLMS)
#error "This code requires liblms"
#endif

/* hash-sigs LMS HSS includes */
#include <hss.h>

#if defined(WOLFSSL_WC_LMS)
#error "This code is incompatible with wolfCrypt's implementation of LMS."
#endif

/*
 * The hash-sigs LMS lib supports from MIN_HSS_LEVELS to MAX_HSS_LEVELS
 * number of levels of Merkle trees. It allows for the tree height and
 * winternitz parameter to be unique per level.
 */

/* hss structs */
typedef struct hss_working_key hss_working_key;
typedef struct hss_extra_info  hss_extra_info;

struct LmsKey {
    unsigned             levels;                      /* Number of tree levels. */
    param_set_t          lm_type[MAX_HSS_LEVELS];     /* Height param per level. */
    param_set_t          lm_ots_type[MAX_HSS_LEVELS]; /* Winternitz param per level. */
    unsigned char        pub[HSS_MAX_PUBLIC_KEY_LEN];
#ifndef WOLFSSL_LMS_VERIFY_ONLY
    hss_working_key *    working_key;
    write_private_key_cb write_private_key; /* Callback to write/update key. */
    read_private_key_cb  read_private_key;  /* Callback to read key. */
    void *               context;           /* Context arg passed to callbacks. */
    hss_extra_info       info;
#endif /* ifndef WOLFSSL_LMS_VERIFY_ONLY */
    enum wc_LmsState     state;
};

#endif /* WOLFSSL_HAVE_LMS */
#endif /* EXT_LMS_H */
