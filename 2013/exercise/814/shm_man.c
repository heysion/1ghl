#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <error.h>

#ifndef NOFILE
#define NOFILE 3
#endif

void send_shm(int spid,int shmid)
{
  union sigval val;
  struct sigaction act;
  //signal(SIGCHLD, SIG_IGN); /* 忽略子进程结束信号，防止出现僵尸进程 */

  syslog(LOG_DEBUG,"daemon: send shmid %d %d",shmid,getpid());
  val.sival_int = shmid; //send shmid
  sigqueue(spid, SIGRTMIN, val); // 只可以发信号给某个进程，而不能是进程组


}

void read_shm(int spid,int shmid)
{
  int pid2=-1;
  char *shmaddr ;
  struct shmid_ds buf ;
  int flag = 0 ;

  syslog(LOG_DEBUG,"daemon: read shm %d %d",spid,shmid);
  
  flag = shmctl( shmid, IPC_STAT, &buf) ;
  
  if ( flag == -1 )
    {
      perror("shmctl shm error") ;
      return  ;
    }

  syslog(LOG_DEBUG,"shm_segsz =%d bytes shmid %d", buf.shm_segsz ,buf.shm_cpid) ;

  shmaddr = (char *) shmat(shmid, NULL, 0 ) ;
  if ( shmaddr == NULL )
    {
      perror("shmat addr error") ;
      return  ;
    }

  syslog(LOG_DEBUG,"daemon:%s", shmaddr) ;
  shmdt( shmaddr ) ;

  if((pid2 = fork()) == 0)
    {
      send_shm(spid,shmid);

    }
  else
    {
      syslog(LOG_DEBUG," send pid %d shmid%d\n",spid,shmid);
      return ;
    }
}

void daemon2()
{
  int pid;
  int i;
  if(pid = fork()) exit(0); //父进程，退出

  else if(pid < 0) exit(1); //fork失败

  /* 子进程继续执行 */
  setsid(); //创建新的会话组，子进程成为组长，并与控制终端分离

  /* 防止子进程（组长）获取控制终端 */
  if(pid = fork()) exit(0); //父进程，退出

  else if(pid < 0) exit(1); //fork错误，退出

  /* 第二子进程继续执行 , 第二子进程不再是会会话组组长*/

  for(i = 0; i < NOFILE; i++) /* 关闭打开的文件描述符*/
    {
      close(i);
    }
  chdir("/tmp"); /* 切换工作目录 */
  umask(0); /* 重设文件创建掩码 */

}

void handler(int sig, siginfo_t *info, void *ctx)
{

  int shmid=0;
 
  syslog(LOG_DEBUG,"daemon: handler %d %d %d",sig,info->si_int,info->si_pid);
  if((shmid= info->si_int) != -1)
    {
      syslog(LOG_DEBUG,"daemon: from :%d  shmid :%d",info->si_pid,shmid);
      read_shm(info->si_pid,shmid);
    }
}

int main()
{

  int count=0;
  struct sigaction act;
  signal(SIGCHLD, SIG_IGN); /* 忽略子进程结束信号，防止出现僵尸进程 */
  
  openlog("daemon",LOG_CONS | LOG_PID , LOG_USER);

  daemon2();

  syslog(LOG_DEBUG,"daemon: init daemon %d\n",__LINE__);
  
  act.sa_sigaction = handler; //sa_sigaction与sa_handler只能取其一
  sigemptyset(&act.sa_mask);
  sigaddset(&act.sa_mask, SIGRTMIN);
  act.sa_flags = SA_SIGINFO; // 设置标志位后可以接收其他进程
  
  syslog(LOG_DEBUG,"daemon: run daemon %d is init signal\n",__LINE__);
  if (sigaction(SIGRTMIN, &act, NULL) < 0)
    {
      syslog(LOG_DEBUG,"daemon:  get SIGRTMIN signal failed");
    }

  syslog(LOG_DEBUG,"daemon: run daemon %d is listen signal\n",__LINE__);

  while(1);
  pause();

  return 0;
}

