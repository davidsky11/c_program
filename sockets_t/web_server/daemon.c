/*
 * =====================================================================================
 *
 *       Filename:  daemon.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/04/2014 11:18:49 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "daemon.h"


/*
 * 普通进程变成守护进程
 */
int 
daemon_ser(const char *name, int facility)
{
	int i;
	pid_t pid;
	if ((pid = fork()) < 0)
	  return -1;
	else if (pid > 0)
	  _exit(0);

	if (setsid() < 0)
	  return -1;

	signal(SIGHUP, SIG_IGN);
	if ((pid = fork()) < 0)
	  return -1;
	else 
	  _exit(0);

	chdir("/");
	for (i = 0; i < MAXFD; i++)
	  close(i);

	open("/dev/null", O_RDONLY);
	open("/dev/null", O_RDWR);
	open("/dev/null", O_RDWR);
	openlog(name, LOG_PID, facility);
	return 0;
}

/*
 * 自定义输出函数，可以递交给syslog守护进程或者终端
 */
void PST(char *ptr)
{
	syslog(LOG_INFO | LOG_LOCAL7, "%s", ptr);
}
