/*
 * =====================================================================================
 *
 *       Filename:  disc_SIGHUP.c
 *
 *    Description:  exec ./disc_SIGHUP d s s > sig.log 2>&1 
 *
 *        Version:  1.0
 *        Created:  10/07/2014 11:12:16 AM
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
#include <signal.h>
#include "../lib/tlpi_hdr.h"

static void handler(int sig) {
	printf("PID %ld: caught signal %2d (%s)\n", (long) getpid(), sig, strsignal(sig));
}

int main(int argc, char *argv[]) {
	pid_t parentPid, childPid;
	int j;
	struct sigaction sa;

	setbuf(stdout, NULL);

	parentPid = getpid();
	printf("PID of parent process is:	%ld\n", (long) parentPid);
	printf("Foreground process group ID is: %ld\n", (long) tcgetpgrp(STDIN_FILENO));

	for (j=1; j<argc; j++) {
		childPid = fork();
		if (childPid == 0)		/* If child... */
		  if (argv[j][0] == 'd')	/* 'd' --> to different pgrp */
			if (setpgid(0, 0) == -1)
			  errExit("setpgid");

		sigemptyset(&sa.sa_mask);
		sa.sa_flags = 0;
		sa.sa_handler = handler;
		if (sigaction(SIGHUP, &sa, NULL) == -1)
		  errExit("sigaction");
		break;		/* Child exits loop */
	}

	/* All processes fall through to here */

	alarm(60);

	printf("PDI=%ld PGID=%ld\n", (long) getpid(), (long) getpgrp());

	for (;;)
	  pause();		/* Wait for signals */
}


