/* ada_binding.c
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

/* wolfSSL */
#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/ssl.h>

/* These functions give access to the integer values of the enumeration
   constants used in WolfSSL. These functions make it possible
   for the WolfSSL implementation to change the values of the constants
   without the need to make a corresponding change in the Ada code. */
extern int get_wolfssl_error_want_read(void);
extern int get_wolfssl_error_want_write(void);
extern int get_wolfssl_max_error_size (void);
extern int get_wolfssl_success(void);
extern int get_wolfssl_failure(void);
extern int get_wolfssl_verify_none(void);
extern int get_wolfssl_verify_peer(void);
extern int get_wolfssl_verify_fail_if_no_peer_cert(void);
extern int get_wolfssl_verify_client_once(void);
extern int get_wolfssl_verify_post_handshake(void);
extern int get_wolfssl_verify_fail_except_psk(void);
extern int get_wolfssl_verify_default(void);

extern int get_wolfssl_filetype_asn1(void);
extern int get_wolfssl_filetype_pem(void);
extern int get_wolfssl_filetype_default(void);

extern int get_wolfssl_error_want_read(void) {
  return WOLFSSL_ERROR_WANT_READ;
}

extern int get_wolfssl_error_want_write(void) {
  return WOLFSSL_ERROR_WANT_WRITE;
}

extern int get_wolfssl_max_error_size(void) {
  return WOLFSSL_MAX_ERROR_SZ;
}

extern int get_wolfssl_success(void) {
  return WOLFSSL_SUCCESS;
}

extern int get_wolfssl_failure(void) {
  return WOLFSSL_FAILURE;
}

extern int get_wolfssl_verify_none(void) {
  return WOLFSSL_VERIFY_NONE;
}

extern int get_wolfssl_verify_peer(void) {
  return WOLFSSL_VERIFY_PEER;
}

extern int get_wolfssl_verify_fail_if_no_peer_cert(void) {
  return WOLFSSL_VERIFY_FAIL_IF_NO_PEER_CERT;
}

extern int get_wolfssl_verify_client_once(void) {
  return WOLFSSL_VERIFY_CLIENT_ONCE;
}

extern int get_wolfssl_verify_post_handshake(void) {
  return WOLFSSL_VERIFY_POST_HANDSHAKE;
}

extern int get_wolfssl_verify_fail_except_psk(void) {
  return WOLFSSL_VERIFY_FAIL_EXCEPT_PSK;
}

extern int get_wolfssl_verify_default(void) {
  return WOLFSSL_VERIFY_DEFAULT;
}

extern int get_wolfssl_filetype_asn1(void) {
  return WOLFSSL_FILETYPE_ASN1;
}

extern int get_wolfssl_filetype_pem(void) {
  return WOLFSSL_FILETYPE_PEM;
}

extern int get_wolfssl_filetype_default(void) {
  return WOLFSSL_FILETYPE_DEFAULT;
}
