#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct timeval date_t ;

static date_t date_zero = {0L,0L} ;

int main()
{
  date_t star ,end ,diff ;
  diff=end=star = date_zero  ;
  printf("%d ,%d ,%d\n",star.tv_usec,end.tv_usec,diff.tv_usec);

  gettimeofday(&star,NULL);
  printf("%d ,%d ,%d\n",star.tv_usec,end.tv_usec,diff.tv_usec);

  gettimeofday(&end,NULL);
  printf("%d ,%d ,%d\n",star.tv_usec,end.tv_usec,diff.tv_usec);

  diff.tv_usec = end.tv_usec - star.tv_usec ;
  printf("%d ,%d ,%d\n",star.tv_usec,end.tv_usec,diff.tv_usec);


  return 0;
}

