#include <stdlib.h>
#include <stdio.h>

#define init(x) int x=1
#define kp(x) void *x=NULL 

int main()
{

  init(a1);
  kp(a2) ;
  printf("%d\n",a1);
  a1 = 100 ;
  printf("%d\n",a1);

  printf("kp %d %p\n",sizeof(a2),a2);
  a2 = (void *)malloc(10);
  printf("kp %d %p\n",sizeof(a2),a2);
  free(a2);
}
