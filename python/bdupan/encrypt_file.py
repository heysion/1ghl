#encrypt file
import os 
import time as t

file_name = 'abc.txt'
source = os.getenv('HOME')+'/backup'

today = t.strftime('%Y%m%d')
now   = t.strftime('%H%M%S')

zip_cmd = "zip -qr'%s'%s"% (

def func():
    print 'Hello word'
    print source
    print today
    print now
