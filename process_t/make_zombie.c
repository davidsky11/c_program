/*
 * =====================================================================================
 *
 *       Filename:  make_zombie.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/24/2014 10:31:49 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <signal.h>
#include <libgen.h>

#include "../lib/tlpi_hdr.h"

#define CMD_SIZE 200

int main(int argc, char *argv[]) {
	char cmd[CMD_SIZE];
	pid_t childPid;

	setbuf(stdout, NULL);

	printf("Parent PDI=%ld\n", (long) getpid());

	switch (childPid = fork()) {
		case -1:
			errExit("fork");

		case 0:
			printf("Child (PID=%ld) exiting\n", (long) getpid());

		default:
			sleep(3);
			snprintf(cmd, CMD_SIZE, "ps | grep %s", basename(argv[0]));
			system(cmd);

			if (kill(childPid, SIGKILL) == -1)
			  errMsg("kill");
			sleep(3);
			printf("After sending SIGKILL to zombie (PID=%ld):\n", (long) childPid);
			system(cmd);

			exit(EXIT_SUCCESS);
	}
}
