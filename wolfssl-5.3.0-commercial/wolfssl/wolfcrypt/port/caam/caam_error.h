/* caam_error.h
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef CAAM_ERROR_H
#define CAAM_ERROR_H

int caamParseError(unsigned int error);
int caamParseDECOError(unsigned int error);
int caamParseCCBError(unsigned int error);
unsigned int caamParseJRError(unsigned int error);

#endif /* CAAM_ERROR_H */
