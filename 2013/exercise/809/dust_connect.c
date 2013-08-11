#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<signal.h>

int main(int argc ,char **argv)
{
  char buf[100]="Helloe Heysion";
 if (argc != 2)
    {
        fprintf(stderr, "Usage %s pid\n", argv[0]);
	return 0;
    }

    pid_t pid = atoi(argv[1]); //字符串转换为整数
    printf("dust send pid %d %d\n",pid,SA_SIGINFO);
    union sigval val;
    val.sival_ptr=buf;
    //    val.sival_int = 100;
    //    strcpy(val.sival_ptr,(void *)("Hello Heysion"));
    //    val.sival_ptr=(void *)malloc(100);
    //    printf("%x %s\n",val.sival_ptr,(char *)val.sival_ptr);
    //    memcpy(val.sival_ptr,buf,100);
    //    printf("%s\n",(char *)val.sival_ptr);
    sigqueue(pid, SIGRTMIN, val); // 只可以发信号给某个进程，而不能是进程组
    //    printf("send %d is %d",pid,val.sival_int);
  return 0;
}
