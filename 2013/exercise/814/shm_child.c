#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <error.h>
#include <syslog.h>


int send_shmid,recv_shmid;
#define PSIZE 128

void clean_shm(int sig, siginfo_t *info, void *ctx)
{
  printf("get signal from: %d\n",info->si_pid);
  if(( (recv_shmid = info->si_int ) != -1) && (recv_shmid != 0) && (recv_shmid == send_shmid))
    {
      printf("child: release %d mem",recv_shmid);
      printf("recv shm is ok %d\n",recv_shmid);
      shmctl(recv_shmid, IPC_RMID, NULL) ;
      exit(0);
    }
  else
    {
      syslog(LOG_DEBUG,"child: i didn't know who is %d,%d",recv_shmid,info->si_pid);
    }
}

void get_receipt()
{
  struct sigaction act;
  act.sa_sigaction = clean_shm; //sa_sigaction与sa_handler只能取其一
  sigemptyset(&act.sa_mask);
  sigaddset(&act.sa_mask, SIGRTMIN);
  act.sa_flags = SA_SIGINFO; // 设置标志位后可以接收其他进程

  printf("child:  get receipt %d shmid %d",getpid(),send_shmid);
  if (sigaction(SIGRTMIN, &act, NULL) < 0)
    {
      printf("child:  get SIGRTMIN signal failed");
    }

    while(1);
    pause();
}

int main(int argc ,char **argv)
{
  pid_t pid = -1;

  char*         shmaddr;
  union sigval val;

  signal(SIGCHLD, SIG_IGN); /* 忽略子进程结束信号，防止出现僵尸进程 */
  if (argc != 2)
    {
      fprintf(stderr, "Usage %s pid\n", argv[0]);
      return 0;
    }

  pid = atoi(argv[1]); //字符串转换为整数
  send_shmid = shmget(IPC_PRIVATE, PSIZE, IPC_CREAT|0600 ) ;

  printf("child:init shm is ok %d %d\n",send_shmid,getpid());
  if ( send_shmid < 0 )
    {
      perror("child:get shm  ipc_id error") ;
      return -1 ;

    }

  shmaddr = (char *)shmat( send_shmid, NULL, 0 ) ;

  if ( shmaddr == NULL )
    {
      perror("shmat addr error") ;
      return -1 ;
    }

  printf("child:get shm is ok %d\n",send_shmid);

  strcpy( shmaddr, "Hi, I am child process!\n") ;
  shmdt( shmaddr ) ;

  printf("child:send pid %d %d\n",pid,SA_SIGINFO);

  val.sival_int = send_shmid; //send shmid
  sigqueue(pid, SIGRTMIN, val); // 只可以发信号给某个进程，而不能是进程组
  printf("child:send shm is ok %d\n",send_shmid);

  get_receipt();

  return 0;
}
