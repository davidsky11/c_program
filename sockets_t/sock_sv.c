/*
 * =====================================================================================
 *
 *       Filename:  sock_sv.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/20/2014 10:22:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/tpli_hdr.h"

#define SERV_PORT	16858
#define BUF_SIZE	1024
#define FILE_NAME_SIZE	512

int 
main(int argc, char *argv[])
{
	int sfd, cfd;
	size_t numRead;
	socklen_t len;
	char filename[FILE_NAME_SIZE + 1];
	char buf[BUF_SIZE];
	struct sockaddr_in servaddr, cliaddr;
	
	if (sfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	  errExit("socket");
	
	memset(&servaddr, 0, sizeof(struct sockaddr_in));
//	bzero(&servaddr, sizeof(servaddr));
	servaddr.sa_family = AF_INET;
	servaddr.sin_addr.s_addr = htons(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);

	bzero(buf, sizeof(buf));

	if (bind(sfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1)
	  errExit("bind");

	if (listen(sfd, SOMAXCONN) == -1)
	  errExit("listen");

	while (1)
	{
		len  = sizeof(cliaddr);

		if(cfd = accept(servaddr, (struct sockaddr *) &cliaddr, &len) < 0)
		{
			printf("Server Accept Failed...\n");
			break;
		}

		len = recv(cfd, buf, BUF_SIZE, 0);
		if (len < 0)
		{
			printf("Server Received Data Failed!\n");
			break;
		}

		strncpy(filename, buf,
					strlen(buf) > FILE_NAME_SIZE ? FILE_NAME_SIZE : strlen(buf));

		FILE *fp = fopen(filename, "r");
		if (fp == NULL)
		  printf("File: \t%s Not Found!\n", filename);
		else
		  bzero(buf, BUF_SIZE);
		numRead = 0;
		while ((numRead = fread(buf, sizeof(char), BUF_SIZE, fp)) > 0)
		{
			printf("numRead = %d\n", numRead);

			if (send(cfd, buf, numRead, 0) < 0)
			{
				printf("Send File: \t%s Failed!\n", filename);
				break;
			}

			bzero(buf, sizeof(buf));
		}
		fclose(fp);
		printf("File:\t%s Transfer Finished!\n", filename); 
	}
	close(cfd);
	close(sfd);

	return 0;
}
