/*
 * =====================================================================================
 *
 *       Filename:  fork_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2014 01:47:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "../lib/tlpi_hdr.h"

static int idata = 111;

int main(int argc, char *argv[]) {
	int istack = 222;
	pid_t childPid;

	switch (childPid = fork()) {
		case -1:
			errExit("fork");

		case 0:
			idata *= 3;
			istack *= 3;
			break;

		default:
			sleep(3);
			break;
	}

	printf("PID=%ld %s idata=%d istack=%d\n", (long) getpid(), (childPid == 0) ? "(child)" : "(parent)", idata, istack);
	exit(EXIT_SUCCESS);
}
