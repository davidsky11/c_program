/*
 * =====================================================================================
 *
 *       Filename:  id_echo_cl.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 02:49:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "id_echo.h"

int
main(int argc, char *argv[])
{
	int sfd, j;
	size_t len;
	ssize_t numRead;
	char buf[BUF_SIZE];

	/* Construct server address from first command-line argument */

	sfd = inetConnect(argv[1], SERVICE, SOCK_DGRAM);
	if (sfd == -1)
	  fatal("Could not connect to server socket");

	/* Send remaining command-line arguments to server as separate datagrams */

	for (j = 2; j < argc; j++) {
		len = strlen(argv[j]);
		if (write(sfd, argv[j], len) != len)
		  fatal("partial/failed write");

		numRead = read(sfd, buf, BUF_SIZE);
		if (numRead == -1)
		  errExit("read");

		printf("[%ld bytes] %.*s\n", (long) numRead, (int) numRead, buf);
	}

	exit(EXIT_SUCCESS);
}
