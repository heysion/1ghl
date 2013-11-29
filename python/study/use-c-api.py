#use c api
import ctypes as ct
lib = ct.CDLL("./libtest.so")

print lib.add(10)

