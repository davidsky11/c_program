/*
 * =====================================================================================
 *
 *       Filename:  env_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/10/2014 08:57:01 AM
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

void main(void) {
	char *buf;

	buf = getenv("PATH");

	printf("%s\n", buf);
}
