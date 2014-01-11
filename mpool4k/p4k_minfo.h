#ifndef _P4K_MEM_INFO_
#define _P4K_MEM_INFO_

#include "pool4k.h"

int init_info(head_t hd,size_t size)
{
  int i ;
  pinfo_t pool,temp,t;

  i = size > POOL_LEN_D ? size : POOL_LEN_D ;
  /* the first mem info */
  pool = (pinfo_t )malloc(sizeof(info_t)) ;
  pool->mem = (void *)malloc(POOL_SIZE) ;
  pool->next = NULL ;
  pool->up = NULL ;
  pool->pdx = pool->mem ;
  pool->end = pool->mem ;
  pool->len = POOL_SIZE ;
  pool->max = POOL_SIZE ;
  pool->active = 1 ;
  /* register the head info */
  hd->info1 = hd->info0 = (info_t *)pool ;
  hd->info_max = POOL_SIZE ;
  hd->info_free = NULL ;
  i-- ;

  t = pool ;
  for( ;i > 0 ;i--)
    {
      temp = (pinfo_t )malloc(sizeof(info_t)) ;
      temp->mem = (void *)malloc(POOL_SIZE) ;
      temp->pdx = temp->mem ;
      temp->end = temp->mem ;
      temp->len = POOL_SIZE ;
      temp->max = POOL_SIZE ;
      temp->active = 1 ;

      t->next = (pinfo_t )temp ;      
      temp->up = t ;
      temp->next = NULL ;
      t = temp ;

    }

  return 0 ;
}

int del_info(head_t hd)
{
  int i=0;
  pinfo_t t,pool;
  
  pool = hd->info0;
  t = pool ;
  while(pool)
    {
      t = (pinfo_t )(pool->next) ;
      free(pool->mem) ;
      free(pool);
      pool = t;
      i++;
      printf("del %d\n" ,i) ;

    }
  return 0 ;
}

#endif
