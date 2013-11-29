#use class
class people:
    name = ''
    age = 0
    __weight = 0

    def __init__(self,n,a,w):
        self.name = n 
        self.age = a 
        self.__weight = w

    def p(self):
        print('the name is %s,%d old ' %(self.name,self.age))



p = people('name',10,20)
p.p()

#people.p()


