a=['abc' ,'123' ,'ABDD']
for i in range(len(a)):
 print i ,a[i] ,len(a) ,len(a[i])

for i in range(10):
 print i


#while True:
# pass

def fib(n):
 """Print a Fib """
 a ,b = 0 ,1
 while b < n:
  print b,
  a ,b = b ,a+b

fib(30)

