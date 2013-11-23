#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "make_msg.h"

#define u_char unsigned char 

#define FILE_LENGTH 256
#define TEXT_BUF  1024


void usage(char *p);

int make_xml(int count,char **list,char *buf);

int main(int argc,char ** argv)
{
  list_node *list_head;
  list_node *node1;
  list_node *node2;
  char buf1[10]="abc";
  char buf2[10]="123";
  char buf3[10]="abc1";
  char buf4[10]="123a";
  
  list_head =(list_node *)malloc(sizeof(list_node));
  node1 =(list_node *)malloc(sizeof(list_node));
  node2 =(list_node *)malloc(sizeof(list_node));
  list_head->next = node1;
  node1->next = node2;
  node2->next=NULL;
  
  get_key(node1->node)= buf1;
  node1->node.key.len=3;

  node1->node.value.data = buf2;
  node1->node.value.len=3;
  
  printf("abc");

  return 0;
}


int main_old(int argc,char ** argv)
{
  FILE *fp_out;
  char filename[256]={0,};
  char out[TEXT_BUF]={0,};
  list_node *list_head;

  if(argc < 3)
    {
      usage(argv[0]);
      return ;
    }

  if(argv[1][0] == 'F')
    {
      printf("abs!\n");
      strncpy(filename,argv[1]+1,FILE_LENGTH);
    }
  else 
    {
      strncpy(filename,argv[1],FILE_LENGTH);
      printf("env %s\n",argv[1]);
    }

  printf("file name :%s \n",filename);

  fp_out = fopen(filename,"w+");
  if(fp_out == NULL )
    {
      printf("file open error:%s\n",filename);
      return ;
    }

  make_xml(argc-2,argv+2,out); 
 fprintf(fp_out,out);
  fflush(fp_out);
  fclose(fp_out);

  return 0;
}

void usage(char *p)
{
  printf("%s : %s arg1 arg2 arg3... \n arg1: is filepath ,if the filepath is absolutely path must use F/xx/xx \n arg2: is the key-value number \n other is the key-value list",p,p);
}

#define NEW_LINE " \n" 

int make_xml(int count,char **list,char *buf)
{
  char key[128]={0,};
  char value[1024]={0,};
  char temp[1024]={0,};
  char *p1=NULL,*p2=NULL;
  int  len=0;
  int  i=0;
  if(list == NULL )
    return -1;

  for(i=0 ;i<count ;i++)
    {
      if(list[i][0] == '<' && (p2=strchr(list[i],'>')))
	{
	  p1 = ++list[i];
	  len = p2 -p1;
	  strncpy(key,p1,(len < 128 ? len : 128));
	  len = 0;
	  p1= ++ p2;
	  len=strlen(p1);
	  strncpy(value,p1,(len < 1024 ? len : 1024));
	  printf("\n%s \n%s\n",key,value);
	}
      else
	{
	  continue;
	}
   
      sprintf(temp,"<%s>%s</%s>%s",key,value,key,NEW_LINE);
      strcat(buf,temp);
      temp[0]='\0';
      printf(buf);

    }
      return 0;
}
