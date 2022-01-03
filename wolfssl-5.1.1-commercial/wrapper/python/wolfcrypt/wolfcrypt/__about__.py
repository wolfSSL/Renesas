# __about__.py
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

metadata = dict(
  __name__         = "wolfcrypt",
  __version__      = "0.1.9",
  __license__      = "GPLv2 or Commercial License",
  __author__       = "wolfSSL Inc.",
  __author_email__ = "info@wolfssl.com",
  __url__          = "https://wolfssl.github.io/wolfcrypt-py",
  __description__  = \
    u"A Python library that encapsulates wolfSSL's wolfCrypt API.",
  __keywords__     = "security, cryptography, ssl, embedded, embedded ssl",
  __classifiers__  = [
    u"License :: OSI Approved :: GNU General Public License v2 (GPLv2)",
    u"License :: Other/Proprietary License",
    u"Operating System :: OS Independent",
    u"Programming Language :: Python :: 2.7",
    u"Programming Language :: Python :: 3.5",
    u"Topic :: Security",
    u"Topic :: Security :: Cryptography",
    u"Topic :: Software Development"
  ]
)

globals().update(metadata)

__all__ = list(metadata.keys())
