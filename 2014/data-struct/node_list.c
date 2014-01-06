#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node{
  int age;
  struct LNode *next;
}LNode , *List;

List init_list(List p,int len)
{
  int i;
  List temp,t;

  t = p;

  for(i=len ;i > 0 ;i-- )
    {
      temp = (List )malloc(sizeof(LNode) );
      temp->age = 10 * i ;
      t->next = (struct LNode * )temp;
      t = temp;

    }

  return p;

}

int delete_list(List p)
{
  int i=0;
  List t;
  t = p;

  while(t)
    {
      t = (List)(p->next) ;
      free(p);
      p = t;
      i++;
      printf("del %d\n",i);
    }

}

int main(int argc,char **argv)
{
  int i;
  List p,t;
  p = (List )malloc(sizeof(LNode) );
  p->next = NULL;

/*  init_list(p,atoi(argv[1])); */
init_list(p,3);
  
  printf("%d %d\n",sizeof(p),sizeof(struct Node));

  t = (List)(p->next) ;
  for(i=1 ;t != NULL ; i++)
    {
      printf("%d : %d \n",i,t->age);
      t=(struct Node *)t->next;
    }
 
  delete_list(p);

  return 0;
}

