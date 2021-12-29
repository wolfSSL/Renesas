# random.py
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
from wolfcrypt._ffi  import ffi as _ffi
from wolfcrypt._ffi  import lib as _lib
from wolfcrypt.utils import t2b

from wolfcrypt.exceptions import *


class Random(object):
    """
    A Cryptographically Secure Pseudo Random Number Generator - CSPRNG
    """
    def __init__(self):
        self.native_object = _ffi.new("WC_RNG *")

        ret = _lib.wc_InitRng(self.native_object)
        if ret < 0:
            self.native_object = None
            raise WolfCryptError("RNG init error (%d)" % ret)


    def __del__(self):
        if self.native_object:
            try:
                _lib.wc_FreeRng(self.native_object)
            except AttributeError:
                # Can occur during interpreter shutdown
                pass


    def byte(self):
        """
        Generate and return a random byte.
        """
        result = _ffi.new('byte[1]')

        ret = _lib.wc_RNG_GenerateByte(self.native_object, result)
        if ret < 0:
            raise WolfCryptError("RNG generate byte error (%d)" % ret)

        return _ffi.buffer(result, 1)[:]


    def bytes(self, length):
        """
        Generate and return a random sequence of length bytes.
        """
        result = _ffi.new('byte[%d]' % length)

        ret = _lib.wc_RNG_GenerateBlock(self.native_object, result, length)
        if ret < 0:
            raise WolfCryptError("RNG generate block error (%d)" % ret)

        return _ffi.buffer(result, length)[:]
