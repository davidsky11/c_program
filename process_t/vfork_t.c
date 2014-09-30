/*
 * =====================================================================================
 *
 *       Filename:  vfork_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2014 02:55:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "../lib/tlpi_hdr.h"

int main (int argc, char *argv[]) {
	int istack = 222;

	switch (vfork()) {
		case -1:
			errExit("vfork");

		case 0:		/* Child executes first, in parent's memory space */
			sleep(3);	/* Even if we sleep for a while, parent still is not scheduled */

			write(STDOUT_FILENO, "Child executing\n", 16);
			istack *= 3;	/* This change will be seen by parent */
			_exit(EXIT_SUCCESS);

		default:		/* Parent is blocked until child exits */
			write(STDOUT_FILENO, "Parent executing\n", 17);
			printf("istack=%d\n", istack);
			exit(EXIT_SUCCESS);
	}
}
