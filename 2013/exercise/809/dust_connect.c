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

 if (argc != 2)
    {
        fprintf(stderr, "Usage %s pid\n", argv[0]);
	return 0;
    }

    pid_t pid = atoi(argv[1]); //字符串转换为整数
    printf("dust send pid %d %d\n",pid,SA_SIGINFO);
    union sigval val;
    val.sival_int = 100;
    sigqueue(pid, SIGRTMIN, val); // 只可以发信号给某个进程，而不能是进程组
    printf("send %d is %d",pid,val.sival_in);
  return 0;
}
