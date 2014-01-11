#ifndef _POOL_4K_
#define _POOL_4K_

#include <string.h>

#define POOL_SIZE 4096
#define POOL_LEN_D 4

typedef struct mem_head *phead_t ;
typedef struct mem_head
{
  info_t *info0 ;		/* the first mem info  */
  info_t *info1 ;		/* the current mem info */
  large_t *large0 ;		/* the first mem large */
  large_t *large1 ;		/* the current mem large */
  file_t  *file0 ;		/* the first file */
  file_t  *file1 ;		/* the current file */
  log_t *log ;			/* the log  */
  free_t *info_free ;		/* the free mem info */
  free_t *large_free ;		/* the free mem large */
  free_t *file_free ;		/* the free file  */
  size_t info_max ;		/* the current info max */
  size_t large_max ;		/* the current large max */

}mhead,head_t;

typedef struct mem_free * pfree_t ;
typedef struct mem_free
{
  void *p ;
  size_t max ;
  size_t size ;
}mfree ,free_t ;

int init_mfree(head_t *hd)
{

  return 0;
}
int add_mfree(head_t *hd)
{

  return 0;
}

typedef struct log_s * plog_t ;
typedef struct log_s{
  FILE *p ;
}log_t;

typedef struct mem_large * plarge_t ;
typedef struct mem_large
{
  void * mem ;			/* mem data */
  info_t *next ;		/* the next mem */
  info_t *up ;			/* the up mem */
  size_t len ;			/* the mem length */
  size_t active ;		/* 0 or 1 ,the zero is failed  */
}mlarge,large_t;

typedef struct mem_file * pfile_t ;
typedef struct mem_file
{
  FILE *p ;
}mfile,file_t;



typedef struct mem_info *pinfo_t ;
typedef struct mem_info
{
  void * end ;			/* the end position */
  void * pdx ;			/* the start position */
  void * mem ;			/* mem data */
  info_t *next ;		/* the next mem */
  info_t *up ;			/* the up mem */
  size_t len ;			/* the mem length */
  size_t max ;			/* current max mem */
  size_t active ;		/* 0 or 1 ,the zero is failed  */
}minfo ,info_t;


#endif
