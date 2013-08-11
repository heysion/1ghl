#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

#ifndef NOFILE
#define NOFILE 3
#endif

void mpc_daemon()
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
  syslog(LOG_DEBUG,"mpc_daemon:  %d value %d",sig,info->si_value.sival_int);
}

int main()
{

  int count=0;
  struct sigaction act;
  signal(SIGCHLD, SIG_IGN); /* 忽略子进程结束信号，防止出现僵尸进程 */
  
  openlog("mpc_daemon",LOG_CONS | LOG_PID , LOG_USER);

  mpc_daemon();

  syslog(LOG_DEBUG,"mpc_daemon: init daemon %d\n",__LINE__);
  /*
  while(1)
    {
      sleep(1);
      openlog("mpc_daemon",LOG_CONS | LOG_PID , LOG_USER);
      syslog(LOG_DEBUG,"mpc_daemon: %d\n",count++);
    }
  */


    act.sa_sigaction = handler; //sa_sigaction与sa_handler只能取其一
    //sa_sigaction多用于实时信号，可以保存信息
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGRTMIN);
    act.sa_flags = 0; // 设置标志位后可以接收其他进程
    //    act.sa_flags = SA_SIGINFO; // 设置标志位后可以接收其他进程
    // 发送的数据，保存在siginfo_t结构体中

    if (sigaction(SIGRTMIN, &act, NULL) < 0)
      {
	syslog(LOG_DEBUG,"mpc_daemon:  get SIGRTMIN signal failed");
      }

    while(1);

  return 0;
}

