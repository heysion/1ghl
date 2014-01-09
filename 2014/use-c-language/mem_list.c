#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memwatch.h"

typedef struct mem_list * plist_t ;
typedef struct mem_list list_t ;
typedef struct mem_list
{
  void *d;
  list_t *next;
}mlist;

int add_list(list_t *pool,void *d)
{
  list_t *t;
  list_t *temp;
 
  if(NULL != pool)
    {
      t = pool->next;
      if(NULL == t && NULL == pool->d)
	{
	  pool->d = d ;
	  pool->next = NULL ;
	  return 0;
	}else if(NULL == t && NULL != pool->d)
	{
	  temp = (list_t *)malloc(sizeof(list_t)) ;
	  temp->d = (void *)d ;
	  temp->next = NULL ;
	  pool->next = temp ;

	  return 0;
	}
      else
	{
	  temp = (list_t *)malloc(sizeof(list_t)) ;
	  temp->d = d ;
	  temp->next = pool->next ;
	  pool->next= temp ;

	  return 0;
	}
    }
  else
    {
      return -1;
    }
  return 1;
}

int del_list(list_t *pool)
{
  list_t *t;
  for(t=pool;t!=NULL;t=t->next)
    {
      free(t->d);
      free(t);      
    }

  /*
  t = pool->next ;
  free(pool->d);
  free(pool);
  pool= t;
  t = pool->next ;
  free(pool->d);
  free(pool);
  pool= t;
  t = pool->next ;
  free(pool->d);
  free(pool);
  */  
  return 0;
}
int main()
{
  list_t *pool ;
  char *p[3];
  int i =0;

  mwDoFlush(1);
  pool = (plist_t )malloc(sizeof(list_t)) ;
  pool->next = NULL ;
  pool->d = NULL ;
  for(;i<3;i++)
    {
      p[i]=(char *)malloc(i+10);
      add_list(pool,(void *)p[i]);
    }
  
  del_list(pool);
  return 0;
}
