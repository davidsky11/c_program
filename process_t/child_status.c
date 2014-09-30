/*
 * =====================================================================================
 *
 *       Filename:  child_status.c
 *
 *    Description:  ./child_status 23
 *					./child_status &
 *					$ kill -STOP {PID}
 *					$ kill -CONT {PID}
 *
 *        Version:  1.0
 *        Created:  09/24/2014 09:58:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <sys/wait.h>
#include <sys/types.h>

#include "print_wait_status.h"
#include "../lib/tlpi_hdr.h"

int main(int argc, char *argv[]) {
	int status;
	pid_t childPid;

	switch(fork()) {
		case -1:
			errExit("fork");

		case 0:
			printf("Child started with PID= = %ld\n", (long) getpid());
			if (argc >1)
			  exit(getInt(argv[1], 0, "exit-status"));
			else 
			for(;;)
				pause();
			exit(EXIT_SUCCESS);

		default:
			for(;;) {
				childPid = waitpid(-1, &status, WUNTRACED
#ifdef WCONTINUED
					| WCONTINUED
#endif
					);
				if (childPid == -1)
					errExit("waitPid");

				printf("waitpid() returned: PID=%ld; status=0x%04x (%d,%d)\n", (long) childPid, (unsigned int) status, status >> 8, status & 0xff);
				printWaitStatus(NULL, status);

				if (WIFEXITED(status) || WIFSIGNALED(status))
					exit(EXIT_SUCCESS);
			}

	}
}
