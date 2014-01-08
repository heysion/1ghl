#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "memwatch.h"

int main()
{
  char * a[3];
  char * p;
  int i=0;

  mwDoFlush(1);

  for (;i<3;i++)
    {
      a[i] = (char *)malloc(10);
      p=a[i];
      strncpy(p,"abc",10);
      printf("%d : %s\n",i,p);
      free(a[i]);
    }

  return 0;
}
