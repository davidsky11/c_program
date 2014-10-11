/*
 * =====================================================================================
 *
 *       Filename:  become_daemon.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/07/2014 11:33:13 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <sys/stat.h>
#include <fcntl.h>
#include "become_daemon.h"
#include "../lib/tlpi_hdr.h"

int becomeDaemon(int flags) {
	int maxfd, fd;

	switch (fork()) {
		case -1:	
			return -1;
		case 0:
			break;
		default:
			_exit(EXIT_SUCCESS);
	}

	if (setsid() == -1)
	  return -1;

	switch (fork()) {
		case -1:
			return -1;
		case 0:
			break;
		default:
			_exit(EXIT_SUCCESS);
	}

	if (!(flags & BD_NO_UMASK0))
	  umask(0);

	if (!(flags & BD_NO_CHDIR))
	  chdir("/");

	if (!(flags & BD_NO_CLOSE_FILES)) {
		maxfd = sysconf(_SC_OPEN_MAX);
		if (maxfd == -1)
		  maxfd = BD_MAX_CLOSE;

		for (fd = 0; fd < maxfd; fd++)
		  close(fd);
	}

	if (!(flags & BD_NO_REOPEN_STD_FDS)) {
		close(STDIN_FILENO);

		fd = open("/dev/null", O_RDWR);

		if (fd != STDIN_FILENO)
		  return -1;
		if (dup2(STDIN_FILENO, STDOUT_FILENO) != STDOUT_FILENO)
		  return -1;
		if (dup2(STDIN_FILENO, STDERR_FILENO) != STDERR_FILENO)
		  return -1;
	}

	return 0;
}
