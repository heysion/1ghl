#test global

def global_func() :
    global x 
    print x
    x = 2
    print x

x = 50 

global_func()

print x
