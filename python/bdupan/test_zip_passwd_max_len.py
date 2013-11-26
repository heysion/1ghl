#test zip passwd max len

import os
import time as t
now = t.strftime('%H%M%S')
index = range(1,201)

for i in range(0,200):
#    cmd = 'zip -qr -P 
    passwd = 'a' * (i+1) 
    cmd = 'zip -qr -P %s test-%s-%s.zip text.out'% (passwd,now,index[i])
#    print cmd
    if os.system(cmd) == 0 :
        print 'Successful '
    else:
        print 'Error'
