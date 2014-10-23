/*
 * =====================================================================================
 *
 *       Filename:  knclient.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/22/2014 09:48:34 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "knlib.h"
#include "../lib/tlpi_hdr.h"

int
main(int argc, char *argv[])
{
	int sfd;
	struct sockaddr_in serv_addr;
	char sendBuf[MAXLINE], recevBuf[MAXLINE], claddrStr[INET_ADDRSTRLEN];

	sfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sfd == -1)
	  errExit("socket");

	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERV_PORT);

	if (argc > 1)
	{
		if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0)
		  fatal("inet_pton failed for address '%s'", argv[1]);
	}
	else
	{
		printf("Usage: %s [ip/hostname] ...", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (connect(sfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1)
	  errExit("connect");

	char *tmp;
	ssize_t n;

	while ((tmp = fgets(sendBuf, sizeof(sendBuf), stdin)) != NULL)
	{
		int k;
		if ((k = write(sfd, sendBuf, sizeof(sendBuf))) < 0)
		{

		}

		if ((n = read(sfd, recevBuf, sizeof(recevBuf))) > 0)
		  printf("SVR: %s", recevBuf);
		else if (n < 0)
		  printf("fail to get data from server %s\n", inet_ntop(AF_INET, 
						  &serv_addr.sin_addr, claddrStr, INET_ADDRSTRLEN));
		else
		{
			printf("%s", "server defunct\nclosing the socket...");
			close(sfd);
		}
	}

	return 0;
}
