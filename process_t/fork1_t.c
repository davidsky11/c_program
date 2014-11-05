/*
 * =====================================================================================
 *
 *       Filename:  fork1_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/27/2014 10:29:41 AM
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

int
main(void)
{
	int i;
	for (i = 0; i < 2; i++) {
		fork();
		printf("ppid=%d, pid=%d, i=%d\n", getppid(), getpid(), i);
	}
	sleep(10);

	return 0;
}
