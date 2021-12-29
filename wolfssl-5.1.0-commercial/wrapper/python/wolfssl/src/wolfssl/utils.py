# -*- coding: utf-8 -*-
#
# utils.py
#
# Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
#
# This file is part of wolfSSL.
#
# Contact licensing@wolfssl.com with any questions or comments.
#
# https://www.wolfssl.com
#/
#/
#/

# pylint: disable=missing-docstring, unused-import, undefined-variable

import sys
from binascii import hexlify as b2h, unhexlify as h2b

_PY3 = sys.version_info[0] == 3
_TEXT_TYPE = str if _PY3 else unicode
_BINARY_TYPE = bytes if _PY3 else str

def t2b(string):
    """
    Converts text to bynary.
    """
    if isinstance(string, _BINARY_TYPE):
        return string
    return _TEXT_TYPE(string).encode("utf-8")
