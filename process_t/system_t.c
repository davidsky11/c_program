/*
 * =====================================================================================
 *
 *       Filename:  system_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/26/2014 10:01:11 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <sys/wait.h>
#include "print_wait_status.h"
#include "../lib/tlpi_hdr.h"

#define MAX_CMD_SIZE 200

int main(int argc, char *argv[]) {
	char str[MAX_CMD_SIZE];
	int status;

	for(;;) {
		printf("Command: ");
		fflush(stdout);
		if (fgets(str, MAX_CMD_SIZE, stdin) == NULL)
		  break;

		status = system(str);
		printf("system() returned: status=0x%04x (%d,%d)\n", (unsigned int) status, status >> 8, status & 0xff);

		if (status == -1)
		  errExit("system");
		else {
			if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
			  printf("(Probably) could not invoke shell\n");
			else
			  printWaitStatus(NULL, status);
		}
	}

	exit(EXIT_SUCCESS);
}
