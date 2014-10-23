/*
 * =====================================================================================
 *
 *       Filename:  knserver.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/22/2014 09:32:56 AM
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
	int sfd, cfd;
	socklen_t len;
	struct sockaddr_in serv_addr, cli_addr;

	sfd = socket(AF_INET, SOCK_STREAM, 0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERV_PORT);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	  errExit("bind");
	if (listen(sfd, BACKLOG) < 0)
	  errExit("listen");

	signal_k(SIGCHLD, sig_chld);

	bzero(&cli_addr, sizeof(cli_addr));

	pid_t pid;
	while (1)
	{
		len = sizeof(struct sockaddr_in);
		cfd = accept(sfd, (struct sockaddr *) &cli_addr, &len);
		if (cfd == -1)
		{
			if (errno == EINTR)
			{
				errMsg("interrupt");
				continue;
			}
			else
			  errExit("accept");
		}

		if ((pid = fork()) == 0)
		{
			char recevBuf[MAXLINE];
			int n;
			close(sfd);
			while ((n = read(cfd, recevBuf, MAXLINE)) > 0)
			{
				printf("Client: %s", recevBuf);
				write(cfd, recevBuf, MAXLINE);
			}
			if (n < 0)
			  errExit("read");
			close(cfd);
			exit(0);
		}
		close(cfd);
	}

	return 0;
}
