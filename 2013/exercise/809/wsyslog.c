#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>


#define LOG_NAME "TestLog"

int main(int argc,char **argv)
{
  openlog(LOG_NAME,LOG_CONS|LOG_PID,LOG_USER);

  if( argc != 2)
    {
      syslog(LOG_INFO,"error in %s\n",argv[0]);
      closelog();
      return 0;
    }

  syslog(LOG_DEBUG,"log in %s  message: %s\n",argv[0],argv[1]);
  closelog();
  return 0;

}

