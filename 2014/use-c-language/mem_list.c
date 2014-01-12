#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct mem_list * plist_t ;
typedef struct mem_list list_t ;
typedef struct mem_list
{
  void *d;
  list_t *next;
}mlist;

list_t *plist ;
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

void * cgmalloc(size_t sz)
{
  list_t *t;
  list_t *temp;
  void * d;
  
  d=malloc(sz);
 start:
   if(NULL != plist)
     {
      t = plist->next;
      if(NULL == t && NULL == plist->d)
	{
	  plist->d = d ;
	  plist->next = NULL ;
	  return d;

	}else if(NULL == t && NULL != plist->d)
	{
	  temp = (list_t *)malloc(sizeof(list_t)) ;
	  temp->d = (void *)d ;
	  temp->next = NULL ;
	  plist->next = temp ;

	  return d;
	}
      else
	{
	  temp = (list_t *)malloc(sizeof(list_t)) ;
	  temp->d = d ;
	  temp->next = plist->next ;
	  plist->next= temp ;

	  return d;
	}
     }
   else
     {
       plist = (plist_t )malloc(sizeof(list_t)) ;
       plist->next = NULL ;
       plist->d = NULL ;
       goto start ;
     }

  return d;
}


int cgfree()
{
  list_t *t;
  int i =0;
  for(t=plist;t!=NULL;t=t->next)
    {
      free(t->d);
      free(t);
      printf("del %d\n",i);
      i++;
    }
  return 0;
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

  for(;i<3;i++)
    {
      p[i]=(char *)cgmalloc(i+10);
      add_list(pool,(void *)p[i]);
    }

  cgfree();
  return 0;
}
int main2()
{
  list_t *pool ;
  char *p[3];
  int i =0;

  //  mwDoFlush(1);
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
