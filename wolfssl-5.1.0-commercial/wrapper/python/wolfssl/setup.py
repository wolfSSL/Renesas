#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# setup.py
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

# pylint: disable=import-error, wrong-import-position

from __future__ import absolute_import
import os
import sys
import shutil
from setuptools import setup, find_packages

sys.path.insert(0, 'src')
from wolfssl.__about__ import METADATA

os.chdir(os.path.dirname(sys.argv[0]) or ".")

LONG_DESCRIPTION = open("README.rst", "rt").read().replace(
    ".. include:: LICENSING.rst\n",
    open("LICENSING.rst", "rt").read()
)

INFO = dict(
    metadata={k[2:-2]: METADATA[k] for k in METADATA},
    contents={
        "long_description" : LONG_DESCRIPTION,
        "package_data"     : {"":  ["*.txt"]},
        "packages"         : find_packages("src"),
        "package_dir"      : {"": "src"},
        "cffi_modules"     : ["./src/wolfssl/build_ffi.py:ffi"],
    },
    requirements={
        "setup_requires"   : ["cffi>=1.6.0"],
        "install_requires" : ["cffi>=1.6.0"],
    },
    scripts={},
    plugins={},
    tests={},
)


def update_certs():
    c_certs_dir = "../../../certs"
    py_certs_dir = "certs"
    certs = [
        "ca-cert.pem",
        "client-cert.pem",
        "client-key.pem",
        "server-cert.pem",
        "server-key.pem",
        "external/ca-digicert-ev.pem"
    ]

    if os.path.isdir(c_certs_dir):
        if not os.path.isdir(py_certs_dir):
            os.makedirs(py_certs_dir)

        for cert in certs:
            shutil.copy(os.path.join(c_certs_dir, cert), py_certs_dir)


if __name__ == "__main__":
    update_certs()

    KWARGS = {k:v for dct in INFO.values() for (k, v) in dct.items()}
    setup(**KWARGS)
