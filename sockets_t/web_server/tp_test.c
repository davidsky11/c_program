/*
 * =====================================================================================
 *
 *       Filename:  server.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/04/2014 11:28:37 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "config.h"
#include "work.h"
#include "daemon.h"
#include "thread_pool_t.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <arpa/inet.h>

char *host = "10.203.138.100";
char *port = "12121";
int daemon_flag = 0;

int
main(int argc, char *argv[])
{
	int listenfd, *connfd, num;
	socklen_t clilen;
	struct sockaddr_in servaddr, cliaddr;
	struct in_addr myaddr;
	const int on = 1;

	if (argc != 3)
	{
		printf("Usage: %s [thread_pool num] [isDaemon 0 1]...\n", argv[0]);
		exit(0);
	}
	
	if (atoi(argv[2]) == 1)
	{
		daemon_ser(argv[0], LOG_USER);
		daemon_flag = 1;
	}
	else
	  daemon_flag = 0;

	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("socket failed!\n");
		exit(0);
	}

	num = atoi(argv[1]);			/* 线程池的大小 */
	bzero(&servaddr, sizeof(servaddr));
	inet_pton(AF_INET, host, &myaddr);
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = myaddr.s_addr;
	servaddr.sin_port = htons(atoi(port));
	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(int));
	if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		printf("bind failed!\n");
		exit(0);
	}

	if (initial_thread_pool(num) != 0)
	{
		printf("initial_thread_pool failed!\n");
		exit(0);
	}

	signal(SIGINT, clear_pool);
	listen(listenfd, 50);
	for (;;)
	{
		clilen = sizeof(struct sockaddr);
		connfd = (int *) malloc(sizeof(int));
		if (connfd == NULL)
		{
			PST("Malloc connfd error");
			exit(0);
		}
		*connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
		if (*connfd < 0)
		{
			free(connfd);
			continue;
		}

		PST("Add a connect");
		insert_task_to_pool(connfd);
	}

	clear_pool(SIGINT);
	exit(0);		
}
