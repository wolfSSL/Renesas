# test_random.py
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
import unittest
from wolfcrypt.random import *


class TestRandom(unittest.TestCase):


    def setUp(self):
        self.random = Random()


    def test_byte(self):
        assert len(self.random.byte()) == 1


    def test_bytes(self):
        assert len(self.random.bytes(1)) == 1
        assert len(self.random.bytes(10)) == 10
        assert len(self.random.bytes(100)) == 100
