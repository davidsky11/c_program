/*
 * =====================================================================================
 *
 *       Filename:  sys_t.c
 *
 *    Description:  KDB test (Kernel Debug Based on sourcecode)
 *
 *        Version:  1.0
 *        Created:  09/15/2014 02:53:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), shiya.gang@163.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main(void) {
	long id;
	id = getpid();
	printf("getpid()=%ld\n", id);
	return 0;
}
