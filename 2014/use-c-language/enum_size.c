/* enmu size */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum t{a=100,b,c}tt;

int main()
{
  tt temp;
  printf("temp :%d\n",sizeof(tt));
  tt *p;
  p =(tt *)malloc(sizeof(tt));
  
  *p=c;
  printf("t:%d\n",*p);

  free(p);
  return 0;
}
