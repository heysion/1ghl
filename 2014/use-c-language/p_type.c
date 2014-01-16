#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>

typedef struct tag{
  char *p;
}tag_t;
typedef tag_t * ptag;
typedef tag_t tag8[8];

int main()
{

  tag_t pa[8];
  tag8 *pp;

  int i=0;

  setenv("MALLOC_TRACE","output.out",1);
  mtrace();

  for(i=0;i<8;i++)
    {
      printf("#%d,%p\n",sizeof(pa[i].p),pa[i].p);
      pa[i].p=(char *)malloc((i+1)*2);

    }
  pp = &pa ;
  

  printf("@%d,%p\n",sizeof(pp),pp[1]);
  //  printf("@%d,%d\n",sizeof(p),sizeof(p[2]));
  for(i=0;i<8;i++)
    {

      free(pa[i].p);
      pa[i].p=NULL;

    }


  return 0;
}
