#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct timeval date_t ;

static date_t date_zero = {0L,0L} ;
#define time_init(a,b,c) date_t a,b,c ;a=b=c=date_zero  
#define time_star(x)   gettimeofday(&x,NULL)
#define time_stop(x)   gettimeofday(&x,NULL)
#define time_diff(a,b,c) c.tv_usec=b.tv_usec-a.tv_usec
#define time_reset(a,b,c) a=b=c=date_zero  

int main(int argc ,char **argv)
{


  void *p ;
  int i = 0,k =0 ;
  int n = 0 ,t = 0,t2=0;

  if(argc != 3)
    {      printf("argv error %ds \n",argc);
      return 0;
    }
  t = atoi(argv[1]);
  t2 = atoi(argv[2]);
  n = t >10 ? t : 10 ;

  p = malloc(10);
  free(p);
  p =NULL ;
  time_init(star,end,diff);
  printf("%d : %d ,%d ,%d\n",n,star.tv_usec,end.tv_usec,diff.tv_usec);

  time_star(star) ;

  for (k=0;k<t2;k++)
    {
      for(i=0 ;i < n ;i++)
	{
	  p =malloc(5000);
	  free(p);
	  p = NULL ;
	}
    }

  n = (t == n ) ? n * 10 : t * 10 ; 
  time_reset(star,end,diff);
  printf("%d : %d ,%d ,%d\n",n,star.tv_usec,end.tv_usec,diff.tv_usec);

  time_star(star) ;

  for (k=0;k<t2;k++)
    {
      for(i=0 ;i < n ; i++)
	{
	  p =malloc(4096);
	  free(p);
	  p = NULL ;
	}

  time_stop(end);
  time_diff(star,end,diff);
  printf("%d : %d ,%d ,%d\n",n,star.tv_usec,end.tv_usec,diff.tv_usec);

  return 0;

}

