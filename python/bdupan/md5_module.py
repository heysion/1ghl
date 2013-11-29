#md5 function
#int md5_hash(const void *buff, size_t len, char *hexsum);
#import ctypes as ct
from  ctypes import *
def md5hash(src):
    md5_lib_path = './'
    md5_lib_file = 'libminmd5.so'
    md5_lib = CDLL(md5_lib_path+md5_lib_file)
    out = create_string_buffer(64)
    md5_lib.md5_hash(src,len(src),out)
    return  out.value




