/*
 * =====================================================================================
 *
 *       Filename:  i6d_ucase_sv.c
 *
 *    Description:  $ ./i6d_ucase_sv &
 *					$ ./i6d_ucase_cl ::1 ciao
 *
 *        Version:  1.0
 *        Created:  10/09/2014 07:41:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "i6d_ucase.h"

int
main(int argc, char *argv[])
{
	struct sockaddr_in6 svaddr;
	int sfd, j;
	size_t msgLen;
	ssize_t numBytes;
	char resp[BUF_SIZE];
	
	sfd = socket(AF_INET6, SOCK_DGRAM, 0);
	if (sfd == -1)
	  errExit("socket");

	memset(&svaddr, 0, sizeof(struct sockaddr_in6));
	svaddr.sin6_family = AF_INET6;
	svaddr.sin6_port = htons(PORT_NUM);

	if (inet_pton(AF_INET6, argv[1], &svaddr.sin6_addr) <= 0)
	  fatal("inet_pton failed for address '%s'", argv[1]);

	/* Send messages to server; echo responses on stdout */	
	
	for (j = 2; j < argc; j++) {
		msgLen = strlen(argv[j]);
		if (sendto(sfd, argv[j], msgLen, 0, (struct sockaddr *) &svaddr,
						sizeof(struct sockaddr_in6)) != msgLen)
		  fatal("sendto");

		numBytes = recvfrom(sfd, resp, BUF_SIZE, 0, NULL, NULL);
		if (numBytes == -1)
		  errExit("recvfrom");

		printf("Response %d: %.*s\n", j - 1, (int) numBytes, resp);
	}

	exit(EXIT_SUCCESS);
}
