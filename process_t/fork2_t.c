/*
 * =====================================================================================
 *
 *       Filename:  fork2_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/27/2014 10:23:11 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <unistd.h>

int
main(void)
{
	int i = 1;
	if (!fork())	i++;
	printf("%d\n", i);

	if (!fork())	i++;
	printf("%d\n", i);

	return 0;
}

/*
 * fork()完成对其调用后将存在两个进程，且每个进程都会从fork()的返回处继续执行
 * A-+---1-+---1
 *   |     |-C-2
 *   |
 *   |-B-2-+---2
 *         |-D-3
 */
