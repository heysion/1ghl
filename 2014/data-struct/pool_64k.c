#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pool_64k.h"
/*
typedef struct mem_info
{
  void * end;
  void * start;
  void * mem;
  mem_info * next;
  size_t len;
  size_t size;
  size_t curr_max;
}pool , *info;
*/


int main(int argc , char **argv)
{

  int i ;
  info p,t;
  
  p = (info)malloc(sizeof(page)) ;
  p->next ;

  init(p,2);

  t = p ;
  for(i =1 ;t != NULL ;i++)
    {
      printf("%d : %d ,%d ,%d\n",i,t->len,t->size,t->curr_max);
      t=(info ) t->next ;
    }

  delete(p);
  return 0;
}
