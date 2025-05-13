/* pico.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef _WOLFPORT_RPIPICO_H_
#define _WOLFPORT_RPIPICO_H_
#if defined(WOLFSSL_RPIPICO)

WOLFSSL_LOCAL int wc_pico_rng_gen_block(unsigned char* output, unsigned int sz);

#endif /* WOLFSSL_RPPICO */
#endif /* _WOLFPORT_RPIPICO_H_ */
