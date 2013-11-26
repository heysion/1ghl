#file test

fp= file('test.out','w+')
fp.write('abc')
fp.close()

fp= file('test.out')
while True :
    line = fp.readline()
    if len(line) == 0 :
        break 
    print line
fp.close()

