	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>


	int main(int argc,char **argv )
{
  int opt;

  while( (opt = getopt(argc,argv,"a:b:c"))!=-1){
    switch(opt){
    case 'a':{
      printf("a:%s\n",optarg);
      break;
    }

    case 'b':{
      printf("b:%s\n",optarg);
      break;
    }

    case 'c':{
      printf("c:%s\n",optarg);
      break;
    }

    default:{
      printf("default:%s\n",optarg);
      break;
    }
    }
  }

  return 0;
}


