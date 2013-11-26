#use pickle

import cPickle as cpick
filename='cpick-file.out'
#file_data=['abc','123','343434']
#file_data2={'heysion':'heysions@gmail.com','yhsponder':'yhsponder@gmail.com'}

#fp = file(filename,'a+')

#cpick.dump(file_data,fp)
#cpick.dump(file_data2,fp)
#fp.close()
#del file_data 

fp= file(filename)
rdata=cpick.load(fp)
print rdata
