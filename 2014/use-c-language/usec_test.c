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

int main()
{

  time_init(star,end,diff);
  printf("%d ,%d ,%d\n",star.tv_usec,end.tv_usec,diff.tv_usec);

  time_star(star) ;
  sleep(1);
  time_stop(end);
  time_diff(star,end,diff);
  printf("%d ,%d ,%d\n",star.tv_usec,end.tv_usec,diff.tv_usec);

  time_reset(star,end,diff) ;
  printf("%d ,%d ,%d\n",star.tv_usec,end.tv_usec,diff.tv_usec);

  time_star(star) ;
  sleep(1);
  time_stop(end);
  time_diff(star,end,diff);
  printf("%d ,%d ,%d\n",star.tv_usec,end.tv_usec,diff.tv_usec);

  return 0;

}

