/*
 * =====================================================================================
 *
 *       Filename:  file_client.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/20/2014 03:42:54 PM
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
	int cfd, receBytes;
	FILE *fp;
	socklen_t len;
	Boolean isExist = FALSE;
	Boolean isOpened = FALSE;

	// 设置一个socket地址结构cli_addr, 代表客户机的interner地址和端口
	struct sockaddr_in serv_addr, cli_addr;
	bzero(&cli_addr, sizeof(cli_addr));
	cli_addr.sin_family = AF_INET;		// internet协议族
	cli_addr.sin_addr.s_addr = htons(INADDR_ANY);	
						// INADDR_ANY表示自动获取本机地址
	cli_addr.sin_port = htons(0); //htons(0);		
						// auto allocated, 让系统自动分配一个空闲端口
						
	// 创建用于internet的流协议(TCP)类型socket，用cfd代表客户端socket
	cfd = socket(AF_INET, SOCK_STREAM, 0);
	if (cfd == -1)
	  errExit("socket");

	if (bind(cfd, (struct sockaddr *) &cli_addr, sizeof(cli_addr)) == -1)
	  errExit("bind");

	// 设置一个socket地址结构serv_addr，代表服务器的internet地址和端口
	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(TRANS_PORT);

	char *tmp;
	if (strcmp(argv[1], "localhost") == 0)
	  tmp = "127.0.0.1";
	else
	  tmp = argv[1];

	// 服务器的IP地址来自程序的参数
	if (inet_pton(AF_INET, tmp, &serv_addr.sin_addr) <= 0)
	  fatal("inet_pton failed for address '%s'", argv[1]);

	// 向服务器发起连接请求，连接成功后cfd代表客户端和服务器端的一个socket连接
	len = sizeof(serv_addr);
	if (connect(cfd, (struct sockaddr *) &serv_addr, len) < 0)
	  errExit("connect");

	char filename[FILE_NAME_MAX_SIZE + 1];
	bzero(filename, sizeof(filename));
	printf("Please input file name on Server:\t");
	scanf("%s", filename);

	receBytes = 0;

	char buf[BUF_SIZE];
	bzero(buf, sizeof(buf));
	strncpy(buf, filename, 
				strlen(filename) > BUF_SIZE ? BUF_SIZE : strlen(filename));
	// 向服务器发送buffer中的数据，此时buffer中存放的是客户端需要接收的文件的名字
	send(cfd, buf, BUF_SIZE, 0);

	// 从服务器端接收数据到buffer中
	bzero(buf, sizeof(buf));
	int length = 0;
	while (length = recv(cfd, buf, BUF_SIZE, 0))
	{
		if (length < 0)
		{
			printf("Receive Data From Server %s Failed!\n", argv[1]);
			break;
		}
		else 
		{
			receBytes += length;
			if (strncmp(NOT_FOUND, buf, sizeof(NOT_FOUND)) == 0) {
				printf("File '%s' can't located on server!\n", filename);
				isExist = FALSE;
				break;
			}
			else
			{
				isExist = TRUE;
			}
		}

		if (isExist) {
			if (!isOpened) {
				fp = fopen(filename, "w");
				if (fp == NULL)
				  errExit("fopen");
				isOpened = TRUE;
			}

			int write_length = fwrite(buf, sizeof(char), length, fp);
			if (write_length < 0)
			{
				printf("File:\t%s Write Failed!\n", filename);
				break;
			}
			bzero(buf, sizeof(buf));
		}
	}

	if (isOpened) {
		printf("Receive File:\t %s (%d bytes) From Server [%s] Finished!\n", filename, receBytes, argv[1]);
		fclose(fp);
	}
	close(cfd);

	return 0;
}
