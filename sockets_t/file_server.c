/*
 * =====================================================================================
 *
 *       Filename:  file_server.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/20/2014 03:12:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "file_trans.h"

int
main(int argc, char *argv[])
{
	struct sockaddr_in svaddr, claddr;
	int sfd, cfd, j;
	socklen_t len;
	ssize_t numBytes;
	char buf[BUF_SIZE];

	sfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sfd == -1)
	  errExit("socket");

	bzero(&svaddr, sizeof(svaddr));
	svaddr.sin_family = AF_INET;			// internet协议族
	svaddr.sin_addr.s_addr = htons(INADDR_ANY); 	// 自动获取本机地址
	svaddr.sin_port = htons(TRANS_PORT);		// 设置端口
	

	if (bind(sfd, (struct sockaddr *) &svaddr, 
					sizeof(struct sockaddr_in)) == -1)
	  errExit("bind");

	if (listen(sfd, BACKLOG) == -1)
	  errExit("listen");

	for(;;)
	{
		len = sizeof(struct sockaddr_in);
		cfd = accept(sfd, (struct sockaddr *) &claddr, &len);
		if (cfd == -1)
		  errExit("accept");

		bzero(buf, sizeof(buf));
		len = recv(cfd, buf, BUF_SIZE, 0);
		if (len < 0)
		{
			printf("Server Received Data Failed!\n");
			break;
		}

		char filename[FILE_NAME_MAX_SIZE + 1];
		bzero(filename, sizeof(filename));
		strncpy(filename, buf,
					strlen(buf) > FILE_NAME_MAX_SIZE ? FILE_NAME_MAX_SIZE : strlen(buf));

		FILE *fp = fopen(filename, "r");
		if (fp == NULL) {
			printf("File:\t%s Not Found!\n", filename);
			strncpy(buf, NOT_FOUND, sizeof(NOT_FOUND));
			send(cfd, buf, BUF_SIZE, 0);
		}
		else
		{
			bzero(buf, BUF_SIZE);
			int file_block_len = 0;
			while ((file_block_len = fread(buf, sizeof(char), BUF_SIZE, fp)) > 0)
			{
				printf("file_block_len = %d\n", file_block_len);

				if (send(cfd, buf, file_block_len, 0) < 0)
				{
					printf("Send File:\t%s Failed!\n", filename);
					break;
				}

				bzero(buf, sizeof(buf));
			}
			fclose(fp);
			printf("File:\t%s Transfer Finished!\n", filename);
		}
		close(cfd);
	}
	close(sfd);

	return 0;
}
