/*
 * =====================================================================================
 *
 *       Filename:  fork_whos_on_first.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2014 03:31:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <sys/wait.h>
#include "../lib/tlpi_hdr.h"

int main(int argc, char *argv[]) {
	int numChildren, j;
	pid_t childPid;

	numChildren = (argc > 1) ? getInt(argv[1], GN_GT_O, "num-children") : 1;

	setbuf(stdout, NULL);

	for (j = 0; j < numChildren; j++) {
		switch (childPid = fork()) {
			case -1:
				errExit("fork");

			case 0:
				printf("%d child\n", j);
				_exit(EXIT_SUCCESS);

			default:
				printf("%d parent\n", j);
				wait(NULL);
				break;
		}
	}

	exit(EXIT_SUCCESS);
}
