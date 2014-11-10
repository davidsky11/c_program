/*
 * =====================================================================================
 *
 *       Filename:  simple_thread.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/26/2014 11:35:41 AM
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
	char *s = (char *) arg;
	printf("%s", s);

	return (void *) strlen(s);
}

int main(int argc, char *argv[]) {
	pthread_t t1;
	void *res;
	int s;

	s = pthread_create(&t1, NULL, threadFunc, "Hello world\n");
	if (s != 0)
	  errExitEN(s, "pthread_create");

	printf("Message from main()\n");
	s = pthread_join(t1, &res);
	if (s != 0)
	  errExitEN(s, "pthread_join");

}
