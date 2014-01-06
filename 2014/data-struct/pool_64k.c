#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pool_64k.h"
#include "memwatch.h"

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

int main2(int argc , char **argv)
{

  int i ;
  info pool,temp,t;


    mwDoFlush(1);

  pool = (info)malloc(sizeof(page)) ;
  pool->next ;


  //  init(p,2);

  pool->mem = (void *)malloc(POOL_SIZE) ;
  pool->start = pool->mem ;
  pool->end = pool->mem ;
  pool->len = POOL_SIZE ;
  pool->size = POOL_SIZE ;
  pool->curr_max = POOL_SIZE ;

  t = pool;
  for(i = 2 ;i > 0 ;i--)
    {
      temp = (info )malloc(sizeof(page)) ;
      temp->mem = (void *)malloc(POOL_SIZE) ;
      t->next = (struct page *)temp ;
      temp->start = temp->mem ;
      temp->end = temp->mem ;
      temp->len = POOL_SIZE ;
      temp->size = POOL_SIZE ;
      temp->curr_max = POOL_SIZE ;
      temp->next = NULL ;
      t = temp ;
    }

  t = pool ;
  for(i =1 ;t != NULL ;i++)
    {
      printf("%d : %d ,%d ,%d\n",i,t->len,t->size,t->curr_max);
      t=(info ) t->next ;
    }

  //  delete(p);


  t = pool ;
  while(pool)
    {
      t = (info )(pool->next) ;
      free(pool->mem) ;
      free(pool);
      pool = t;
      i++;
      printf("del %d\n" ,i) ;

    }


  return 0;
}


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
