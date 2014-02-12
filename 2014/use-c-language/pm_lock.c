#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER ;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER ;

pthread_t tid1,tid2;

int uuid=0;

void *lock_add(void *arg);
void *lock_move(void *arg);

int main(int argc,char **argv)
{
  void * err;
  uuid = 0 ;
  pthread_mutex_lock(&mutex2);

  pthread_create(&tid1,NULL,lock_add,"abc");
  pthread_create(&tid2,NULL,lock_move,"123");
  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);

  pthread_mutex_unlock(&mutex2);

  printf("%d\n",uuid);
  return 0;
}

void *lock_add(void *arg)
{
  unsigned int ssid = 0;

  ssid = (unsigned int )pthread_self();
  pthread_mutex_lock(&mutex);
  printf("[%u]uuid %d\n",ssid,uuid);
  uuid++ ;
  printf("[%u]uuid %d\n",ssid,uuid);
  sleep(1);
  pthread_mutex_unlock(&mutex);

  return NULL ;
}

void *lock_move(void *arg)
{
  unsigned int ssid = 0;

  ssid = (unsigned int )pthread_self();
  
  pthread_mutex_lock(&mutex);
  printf("[%u]uuid %d\n",ssid,uuid);
  uuid-- ;
  printf("[%u]uuid %d\n",ssid,uuid);
  pthread_mutex_unlock(&mutex);
  
  return NULL;
}
