/*
 * =====================================================================================
 *
 *       Filename:  fork_more.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/20/2014 11:26:57 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) 
{
	pid_t fd1, fd2, fd3;

	fd1 = fork();
	printf("fd1 ==> %ld\n", (long) fd1);

	fd2 = fork();
	printf("fd2 ==> %ld\n", (long) fd2);

//	fd3 = fork();
//	printf("fd3 ==> %ld\n", (long) fd3);
}

