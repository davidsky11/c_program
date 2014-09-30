/*
 * =====================================================================================
 *
 *       Filename:  envargs.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/24/2014 03:24:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "../lib/tlpi_hdr.h"

extern char **environ;

int main(int argc, char *argv[]) {
	int j;
	char **ep;

	for (j = 0; j < argc; j++) {
		printf("argv[%d] = %s\n", j, argv[j]);
	}

	for (ep = environ; *ep != NULL; ep++) {
		printf("envrion: %s\n", *ep);
	}

	exit(EXIT_SUCCESS);
}
