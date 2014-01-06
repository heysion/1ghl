#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "memwatch.h"


int main()
{
  void *p;
  
  mwDoFlush(1);
  
  p=(void *)malloc(10);
  free(p);
  return 0;
}
