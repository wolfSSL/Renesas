/* ecc.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifdef HAVE_ECC

#ifndef CTAO_CRYPT_ECC_H
#define CTAO_CRYPT_ECC_H

#include <wolfssl/wolfcrypt/ecc.h>

/* includes for compatibility */
#include <cyassl/ctaocrypt/types.h>
#include <cyassl/ctaocrypt/integer.h>
#include <cyassl/ctaocrypt/random.h>

/* for ecc reverse compatibility */
#ifdef HAVE_ECC
	#define ecc_make_key      wc_ecc_make_key
	#define ecc_shared_secret wc_ecc_shared_secret
	#define ecc_sign_hash     wc_ecc_sign_hash
	#define ecc_verify_hash   wc_ecc_verify_hash
	#define ecc_init          wc_ecc_init
	#define ecc_free          wc_ecc_free
	#define ecc_fp_free       wc_ecc_fp_free
	#define ecc_export_x963   wc_ecc_export_x963
	#define ecc_size          wc_ecc_size
	#define ecc_sig_size      wc_ecc_sig_size
	#define ecc_export_x963_ex      wc_ecc_export_x963_ex
	#define ecc_import_x963         wc_ecc_import_x963
	#define ecc_import_private_key  wc_ecc_import_private_key
	#define ecc_rs_to_sig           wc_ecc_rs_to_sig
	#define ecc_import_raw          wc_ecc_import_raw
	#define ecc_export_private_only wc_ecc_export_private_only

#ifdef HAVE_ECC_ENCRYPT
	/* ecc encrypt */
	#define ecc_ctx_new           wc_ecc_ctx_new
	#define ecc_ctx_free          wc_ecc_ctx_free
	#define ecc_ctx_reset         wc_ecc_ctx_reset
	#define ecc_ctx_get_own_salt  wc_ecc_ctx_get_own_salt
	#define ecc_ctx_set_peer_salt wc_ecc_ctx_set_peer_salt
	#define ecc_ctx_set_info      wc_ecc_ctx_set_info
	#define ecc_encrypt           wc_ecc_encrypt
	#define ecc_decrypt           wc_ecc_decrypt
#endif /* HAVE_ECC_ENCRYPT */
#endif

#endif /* CTAO_CRYPT_ECC_H */
#endif /* HAVE_ECC */

