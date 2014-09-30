/*
 * =====================================================================================
 *
 *       Filename:  thread_cancel.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/30/2014 10:00:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <pthread.h>
#include "../lib/tlpi_hdr.h"

static void *threadFunc(void *arg) {
	int j;
	printf("New thread started\n");		/* May be a cancellation point */
	for (j = 1; ; j++) {
	  printf("Loop %d\n", j);			/* May be a cancellation point */
	  sleep(1);							/* A cancellation point */
	}

	/* NOTREACHED */
	return NULL;
}

int main(int argc, char *argv[]) {
	pthread_t thr;
	int s;
	void *res;

	s = pthread_create(&thr, NULL, threadFunc, NULL);
	if (s != 0)
	  errExitEN(s, "pthread_create");

	sleep(3);		/* Allow new thread to run a while */

	s = pthread_cancel(thr);
	if (s != 0)
	  errExitEN(s, "pthread_cancel");

	s = pthread_join(thr, &res);
	if (s != 0)
	  errExitEN(s, "pthread_join");


	if (res == PTHREAD_CANCELED)
	  printf("Thread was canceled\n");
	else
	  printf("Thread was not canceled (should not happen!)\n");

	exit(EXIT_SUCCESS);
}
