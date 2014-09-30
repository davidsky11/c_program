/*
 * =====================================================================================
 *
 *       Filename:  footprint.c
 *
 *    Description:  Using fork() + wait() to contrlo the memory footprint of an application.
 *
 *        Version:  1.0
 *        Created:  09/17/2014 02:33:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#define _BSD_SOURCE
#include <sys/wait.h>
#include "../lib/tlpi_hdr.h"

static int func(int arg) {
	int j;

	for (j = 0; j < 0x100; j++) 
	  if (malloc(0x8000) == NULL)
		errExit("malloc");

	printf("Program break in child: %10p\n", sbrk(0));

	return arg;
}

int main(int argc, char *argv[]) {
	int arg = (argc > 1)? getInt(argv[1], 0, "arg") : 0;
	pid_t childPid;
	int status;

	setbuf(stdout, NULL);

	printf("Program break in parent: %10p\n", sbrk(0));

	childPid = fork();
	if (childPid == -1)
	  errExit("fork");

	if (childPid == 0)
	  exit(func(arg));

	if (wait(&status) == -1)
	  errExit("wait");

	printf("Program break in parent: %10p\n", sbrk(0));

	printf("Status = %d %d\n", status, WEXITSTATUS(status));

	exit(EXIT_SUCCESS);
}
