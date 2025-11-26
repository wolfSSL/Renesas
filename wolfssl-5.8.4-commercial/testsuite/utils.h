/* utils.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* This is a set of utility functions that are used by testsuite.c. They are
 * also used in api.c but we want to keep the utils for testsuite.c as small
 * as possible. */

#ifndef TESTSUITE_UTILS_H
#define TESTSUITE_UTILS_H

/* Return
 *   tmpDir on success
 *   NULL on failure */
char* create_tmp_dir(char* tmpDir, int len);
/* Remaining functions return
 * 0 on success
 * -1 on failure */
int rem_dir(const char* dirName);
int rem_file(const char* fileName);
int copy_file(const char* in, const char* out);

#endif /* TESTSUITE_UTILS_H */
