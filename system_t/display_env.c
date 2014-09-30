/*
 * =====================================================================================
 *
 *       Filename:  environ_t.c
 *
 *    Description:  display all the environment value  
 *
 *        Version:  1.0
 *        Created:  09/10/2014 10:09:17 AM
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

extern char **environ;

int main(int argc, char *argv[]) {
	char **ep;

	for (ep = environ; *ep != NULL; ep++) {
		puts(*ep);
	}
	exit(EXIT_SUCCESS);
}
