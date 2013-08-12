#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  int i=0;
  void *p=NULL;
  //*p=&((void *)(0x000000ee));
  p=&(*(0x00EE));
  memcpy(p,&(*(0x00ee)),10);
  for(i=0;i<10;i++)
	printf("%x\n",p++);
  return 0;
}
