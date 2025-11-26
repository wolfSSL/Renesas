/* linuxkm_memory.c
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* included by wolfcrypt/src/memory.c */

#if defined(__PIE__) && defined(CONFIG_FORTIFY_SOURCE)
/* needed because FORTIFY_SOURCE inline implementations call fortify_panic(). */
void __my_fortify_panic(const char *name) {
    pr_emerg("__my_fortify_panic in %s\n", name);
    BUG();
}
#endif
