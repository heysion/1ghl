#include <stdio.h>

int main()
{
  int hi = 2;
  int r = 0,r2 = 0;
  int low = 1;
  r = hi<< 4 + low;
  r2 = (hi<<4) + low ;
  printf("%d ,%d\n",r,r2);
  return 0;
}
