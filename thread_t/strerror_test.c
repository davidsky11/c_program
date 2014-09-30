/*
 * =====================================================================================
 *
 *       Filename:  strerror_test.c
 *
 *    Description: 
 *   
 *    (1) gcc strerror_test.c ../lib/error_functions.c strerror.c -o strerror_test1 -pthread
 *    (2) gcc strerror_test.c ../lib/error_functions.c strerror_tsd.c -o strerror_test2 -pthread
 *
 *
 *        Version:  1.0
 *        Created:  09/29/2014 09:59:34 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <pthread.h>
//#include "strerror_t.h"
#include "../lib/tlpi_hdr.h"

static void *threadFunc(void *arg) {
	char *str;

	printf("Other thread about to call strerror()\n");
	str = strerror(EPERM);
	printf("Other thread: str (%p) = %s\n", str, str);

	return NULL;
}

int main(int argc, char *argv[]) {
	pthread_t t;
	int s;
	char *str;

	str = strerror(EINVAL);
	printf("Main thread has called strerror()\n");

	s = pthread_create(&t, NULL, threadFunc, NULL);
	if (s != 0) 
	  errExitEN(s, "pthread_create");

	s = pthread_join(t, NULL);
	if (s != 0)
	  errExitEN(s, "pthread_join");

	printf("Main thread: str (%p) = %s\n", str, str);

	exit(EXIT_SUCCESS);
}
