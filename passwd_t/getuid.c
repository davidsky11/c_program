/*
 * =====================================================================================
 *
 *       Filename:  getpanam_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/10/2014 01:44:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), shiya.gang@163.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

void main(void) {
	struct passwd pwd;
	
	printf("$$$\n");
	printf("%ld %ld\n", (long) (getpwnam("kevin")->pw_uid), (long) (getpwnam("intel")->pw_uid));
	printf("###\n");
}
