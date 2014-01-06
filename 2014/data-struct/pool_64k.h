#ifndef _POOL_64K_
#define _POOL_64K_

#include <string.h>

#define POOL_SIZE 64

typedef struct mem_info
{
  void * end;
  void * start;
  void * mem;
  struct page * next;
  size_t len;
  size_t size;
  size_t curr_max;
}page , *info;

int init(info pool,size_t size)
{
  int i ;
  info temp,t;

  pool->mem = (void *)malloc(POOL_SIZE) ;
  pool->start = pool->mem ;
  pool->end = pool->mem ;
  pool->len = POOL_SIZE ;
  pool->size = POOL_SIZE ;
  pool->curr_max = POOL_SIZE ;

  t = pool;
  for(i = size ;i > 0 ;i--)
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

  return 0 ;
}

int delete(info pool)
{
  int i=0;
  info t;
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
  return 0 ;
}

#endif
