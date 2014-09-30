/*
 * =====================================================================================
 *
 *       Filename:  closeonexec.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/26/2014 09:49:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <fcntl.h>
#include "../lib/tlpi_hdr.h"

int main(int argc, char *argv[]) {
	int flags;

	if (argc > 1) {
		flags = fcntl(STDOUT_FILENO, F_GETFD);
		if (flags == -1)
		  errExit("fcntl - F_GETFD");

		flags |= FD_CLOEXEC;

		if (fcntl(STDOUT_FILENO, F_SETFD, flags) == -1)
		  errExit("fcntl - F_SETFD");
	}

	execlp("ls", "ls", "-l", argv[0], (char *) NULL);
	errExit("execlp");
}
