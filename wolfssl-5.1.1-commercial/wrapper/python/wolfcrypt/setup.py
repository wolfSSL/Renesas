#!/usr/bin/env python
# -*- coding: utf-8 -*-
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

# Python 2.7 Standard Library
from __future__ import absolute_import
import os
import sys
from wolfcrypt.__about__ import metadata
from setuptools import setup, find_packages

os.chdir(os.path.dirname(sys.argv[0]) or ".")

long_description = open("README.rst", "rt").read().replace(
    ".. include:: LICENSING.rst\n",
    open("LICENSING.rst", "rt").read()
)

info = dict(
    metadata     = {k[2:-2]: metadata[k] for k in metadata},
    contents     = {
                     "long_description": long_description,
                     "package_data":     {"":  ["*.txt"]},
                     "packages":         find_packages(),
                     "cffi_modules":     ["./wolfcrypt/build_ffi.py:ffi"],
    },
    requirements = {
                    "setup_requires":    ["cffi>=1.6.0"],
                    "install_requires":  ["cffi>=1.6.0"],
    },
    scripts      = {},
    plugins      = {},
    tests        = {},
)

if __name__ == "__main__":
    kwargs = {k:v for dct in info.values() for (k,v) in dct.items()}
    setup(**kwargs)
