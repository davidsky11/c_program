/*
 * =====================================================================================
 *
 *       Filename:  mem_segments.c
 *
 *    Description:  display all the position of variables in memory.  
 *
 *        Version:  1.0
 *        Created:  09/10/2014 04:45:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), shiya.gang@163.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];			/* Uninitialized data segment */
int primes[] = {2,3,5,7};		/* Initialized data segment */

static int square(int x) {
	int result;

	result = x * x;
	return result;
}

static void doCalc(int val) {
	printf("The square of %d is %d\n", val, square(val));

	if (val < 1000) {
		int t;

		t = val * val * val;
		printf("The cube of %d is %d\n", val, t);
	}
}

int main(int argc, char * argv[]) {
	static int key = 9973;			/* Initialized data segment */
	static char mbuf[10240000];		/* Uninitialized data segment */
	char *p;						/* Allocated in frame for main() */

	p = malloc(1024);				/* Points to memory in heap segment */

	doCalc(key);

	exit(EXIT_SUCCESS);
}
