/*
 * =====================================================================================
 *
 *       Filename:  print_wait_status.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/24/2014 09:48:05 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#define _GNU_SOURCE
#include <string.h>
#include <sys/wait.h>

#include "print_wait_status.h"
#include "../lib/tlpi_hdr.h"

/* Examine a wait() status using the W* macros */
void printWaitStatus(const char *msg, int status) {
	if (msg != NULL) 
	  printf("%s", msg);

	if (WIFEXITED(status)) {
		printf("child exited, status=%d\n", WEXITSTATUS(status));
	} else if (WIFSIGNALED(status)) {
		printf("child killed bu signal %d (%s)", WTERMSIG(status), strsignal(WTERMSIG(status)));
#ifdef WCOREDUMP		/* Not in SUSv3, may be absent on some systems */
		if (WCOREDUMP(status)) {
			printf(" (core demp)");
#endif
		}
		
		printf("\n");
	} else if (WIFSTOPPED(status)) {
		printf("child stopped by signal %d (%s)\n", WSTOPSIG(status), strsignal(WSTOPSIG(status)));
#ifdef WIFCONTINUED	/* SUSv3 has this, but older Linux versions and some other UNIX implementations don't */
	} else if (WIFCONTINUED(status)) {
		printf("child continued\n");
#endif
	} else {		/* Should never happen */
		printf("what happened to this child? (status=%x)\n", (unsigned int) status);
	}
}
