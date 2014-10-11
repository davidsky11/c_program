/*
 * =====================================================================================
 *
 *       Filename:  fork_test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/29/2014 05:23:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int count = 0;

int main(void) {
	int i;
	for (i = 0; i < 2; i++) {
		fork();
		count++;
		printf("+$ %d\t", count);
	}

	printf("  --| \n");

	return 0;
}
