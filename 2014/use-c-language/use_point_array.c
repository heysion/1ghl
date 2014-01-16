#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mcheck.h>

int main()
{
  char * a[3];
  char * p;
  int i=0;


  setenv("MALLOC_TRACE","output.out",1);
  mtrace();

  p=(char *)malloc(3*20);
  free(p);


  return 0;
}
