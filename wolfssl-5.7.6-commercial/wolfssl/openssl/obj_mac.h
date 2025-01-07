/* obj_mac.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* obj_mac.h for openSSL */

#ifndef WOLFSSL_OBJ_MAC_H_
#define WOLFSSL_OBJ_MAC_H_
#ifdef __cplusplus
    extern "C" {
#endif

#define WC_NID_sect163k1 721
#define WC_NID_sect163r1 722
#define WC_NID_sect163r2 723
#define WC_NID_sect193r1 724
#define WC_NID_sect193r2 725
#define WC_NID_sect233k1 726
#define WC_NID_sect233r1 727
#define WC_NID_sect239k1 728
#define WC_NID_sect283k1 729
#define WC_NID_sect283r1 730
#define WC_NID_sect409k1 731
#define WC_NID_sect409r1 732
#define WC_NID_sect571k1 733
#define WC_NID_sect571r1 734

#ifndef OPENSSL_COEXIST

#define NID_sect163k1 WC_NID_sect163k1
#define NID_sect163r1 WC_NID_sect163r1
#define NID_sect163r2 WC_NID_sect163r2
#define NID_sect193r1 WC_NID_sect193r1
#define NID_sect193r2 WC_NID_sect193r2
#define NID_sect233k1 WC_NID_sect233k1
#define NID_sect233r1 WC_NID_sect233r1
#define NID_sect239k1 WC_NID_sect239k1
#define NID_sect283k1 WC_NID_sect283k1
#define NID_sect283r1 WC_NID_sect283r1
#define NID_sect409k1 WC_NID_sect409k1
#define NID_sect409r1 WC_NID_sect409r1
#define NID_sect571k1 WC_NID_sect571k1
#define NID_sect571r1 WC_NID_sect571r1

#endif /* !OPENSSL_COEXIST */

/* the definition is for Qt Unit test */
#define SN_jurisdictionCountryName "jurisdictionC"
#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* WOLFSSL_OBJ_MAC_H_ */

