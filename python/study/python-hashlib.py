#test python hashlib

import hashlib as hlib
md5_func = hlib.md5()
sha1_func = hlib.sha1()

md5_func.update('abc')
hash = md5_func.hexdigest()

print hash

del hash 

sha1_func.update('abc')
hash = sha1_func.hexdigest()

print hash
