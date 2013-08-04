#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *get_err_str(int type) {
	static const char *name[] = {
		[0] = "begin-array",
		[1] = "end-array",
		[2] = "begin-object",
		[3] = "end-object",
		[4] = "name-separator",
		[5] = "value-separator",
		[6] = "string",
		[7] = "number",
		[8] = "boolean",
		[9] = "null",
	};

	return name[type];
}

static const char *get_err_str2(int type) {
	static const char *name[] = {
		 "begin-array",
		 "end-array",
		 "begin-object",
		 "end-object",
		 "name-separator",
		 "value-separator",
		 "string",
		 "number",
		 "boolean",
		 "null",
	};

	return name[type];
}

int main()
{
  int i=0;
  int j=-1;
  void *p;
  int k=1;

  if(i){
    printf("i:ture \n");
  }else{
    printf("i:false \n");
  }

  if(!i){
    printf("i!:ture \n");
  }else{
    printf("i!:false \n");
  }

  if(j){
    printf("j:ture [%d] \n",j);
  }else{
    printf("j:false [%d]\n",j);
  }

  if(!j){
    printf("j!:ture [%d] \n",j);
  }else{
    printf("j!:false [%d]\n",j);
  }

  if(k){
    printf("k:ture [%d] \n",k);
  }else{
    printf("k:false [%d]\n",k);
  }

  if(!k){
    printf("k!:ture [%d] \n",k);
  }else{
    printf("k!:false [%d]\n",k);
  }


  if(p){
    printf("p:ture \n");
  }else{
    printf("p:false \n");
  }

  if(!p){
    printf("p!ture \n");
  }else{
    printf("p!:false \n");
  }

  p = NULL;

  if(!p){
    printf("ture \n");
  }else{
    printf("false \n");
  }

  p=(void * )malloc(10);

  if(p){
    printf("p:ture \n");
  }else{
    printf("p:false \n");
  }

  if(!p){
    printf("ture \n");
  }else{
    printf("false \n");
  }

  if(0){
    printf("0:ture \n");
  }else{
    printf("0:false \n");
  }

  if(!0){
    printf("!0:ture \n");
  }else{
    printf("!0:false \n");
  }

  free(p);

  for(i=0;i<10;i++)
    printf("%s\n",get_err_str2(i));
}



