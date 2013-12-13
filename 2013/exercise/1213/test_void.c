#include <stdlib.h>
#include <stdio.h>

void *fp();
void p();

int main()
{
  void (*h)();
  h = p;
  printf("%d %d\n",sizeof(float *),sizeof(float (*)()));
  return 0;
}
void p()
{
  printf("a");
}

void *fp()
{
  printf("a");
  return (void *)0;
}
