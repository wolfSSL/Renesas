# ax_bsdkm.m4 -- macros for getting attributes of default configured kernel
#
# Copyright (C) 2006-2025 wolfSSL Inc.  All rights reserved.
#
# This file is part of wolfSSL.
#
# Contact licensing@wolfssl.com with any questions or comments.
#
# https://www.wolfssl.com

AC_DEFUN([AC_PATH_DEFAULT_BSDKM_SOURCE],
[
AC_MSG_CHECKING([for default kernel FreeBSD build root])
if test -d /usr/src/sys/; then
  DEFAULT_BSDKM_ROOT=/usr/src/sys/
  AC_MSG_RESULT([$DEFAULT_BSDKM_ROOT])
else
  AC_MSG_RESULT([no default configured kernel found])
fi
])

