/*
 * =====================================================================================
 *
 *       Filename:  ud_ucase_cl.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/09/2014 07:23:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "ud_ucase.h"

int
main(int argc, char *argv[]) 
{
	struct sockaddr_un svaddr, claddr;
	int sfd, j;
	size_t msgLen;
	ssize_t numBytes;
	char resp[BUF_SIZE];

	/* Create client socket; bind to unique pathname (based on PID) */

	sfd = socket(AF_UNIX, SOCK_DGRAM, 0);
	if (sfd == -1)
	  errExit("socket");

	memset(&claddr, 0, sizeof(struct sockaddr_un));
	claddr.sun_family = AF_UNIX;
	snprintf(claddr.sun_path, sizeof(claddr.sun_path), "/tmp/ud_ucase_cl.%ld", (long) getpid());

	if (bind(sfd, (struct sockaddr *) &claddr, sizeof(struct sockaddr_un)) == -1)
	  errExit("bind");

	/* Construct address of server */

	memset(&svaddr, 0, sizeof(struct sockaddr_un));
	svaddr.sun_family = AF_UNIX;
	strncpy(svaddr.sun_path, SV_SOCK_PATH, sizeof(svaddr.sun_path) - 1);

	/* Send messages to server; echo responses on stdout */

	for (j = 1; j < argc; j++) {
		msgLen = strlen(argv[j]);		/* May be longer than BUF_SIZE */
		if (sendto(sfd, argv[j], msgLen, 0, (struct sockaddr *) &svaddr,
						sizeof(struct sockaddr_un)) != msgLen)
		  fatal("sendto");

		numBytes = recvfrom(sfd, resp, BUF_SIZE, 0, NULL, NULL);
		if (numBytes == -1)
		  errExit("recvfrom");
		printf("Response %d: %.*s\n", j, (int) numBytes, resp);
	}

	remove(claddr.sun_path);		/* Remove client socket pathname */
	exit(EXIT_SUCCESS);
}

