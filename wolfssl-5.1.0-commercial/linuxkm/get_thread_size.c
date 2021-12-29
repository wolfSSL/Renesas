/* get_thread_size.c -- trivial program to determine stack frame size
 * for a Linux kernel thread, given a configured source tree.
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef __KERNEL__
#define __KERNEL__
#endif
#include <linux/kconfig.h>
#include <linux/kernel.h>
#include <linux/kthread.h>

extern int dprintf(int fd, const char *format, ...);

int main(__maybe_unused int argc, __maybe_unused char **argv) {
  dprintf(1, "%lu\n",THREAD_SIZE);
  return 0;
}
