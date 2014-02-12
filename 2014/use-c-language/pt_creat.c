#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void * print_abc(void *arg)
{
  pid_t pid;
  pthread_t tid;
  
  printf("start\n");  
  pid = getpid();
  tid = pthread_self();
  printf("pid %u talk [%s] to tid %u\n",(unsigned int)pid,(char *)arg,(unsigned int)tid);
  //  pthread_exit((void *)1);
  sleep(2);
  printf("end\n");
  return NULL ;
}

void * print_ab(void *arg)
{
  pid_t pid;
  pthread_t tid;

  pid = getpid();
  tid = pthread_self();
  printf("pid %u talk [%s] to tid %u\n",(unsigned int)pid,(char *)arg,(unsigned int)tid);
  
  return NULL ;
}
int main(int argc,char **argv)
{
  int err ;
  pthread_t ntid;
  void * tret ;
  err = pthread_create(&ntid,NULL,print_abc,"abc");
  pthread_join(ntid,&tret) ;
  if(err != 0 )
    {
      return -1;
    }
  print_ab("123");
  //  sleep(1);
  pthread_cancel(ntid);
  printf("%p[%d]\n",tret,(tret!=PTHREAD_CANCELED));

  return 0;
}

