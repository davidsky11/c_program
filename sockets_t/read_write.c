/*
 * =====================================================================================
 *
 *       Filename:  read_write.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/01/2014 02:08:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "read_write.h"

ssize_t
readn(int fd, void *buf, size_t count)
{
	size_t nleft = count;
	ssize_t nread;
	char *bufp = (char *)buf;

	while (nleft > 0)
	{
		if ((nread = read(fd, bufp, nleft)) < 0)
		{
			if (errno == EINTR)
			  continue;
			return -1;
		}
		else if (nread == 0)
		  return count - nleft;

		bufp += nread;
		nleft += nread;
	}

	return count;
}

ssize_t
writen(int fd, const void *buf, size_t count)
{
	size_t nleft = count;
	ssize_t nwritten;
	char *bufp = (char *)buf;

	while (nleft > 0)
	{
		if ((nwritten = write(fd, bufp, nleft)) < 0)
		{
			if (errno == EINTR)
			  continue;
			return -1;
		}
		else if (nwritten == 0)
		  continue;

		bufp += nwritten;
		nleft += nwritten;
	}

	return count;
}

ssize_t 
recv_peek(int sockfd, void *buf, size_t len)
{
	while (1)
	{
		int ret = recv(sockfd, buf, len, MSG_PEEK);		
						// 设置标志位后读取后不清除缓冲区
		if (ret == -1 && errno == EINTR)
		  continue;
		return ret;
	}
}

ssize_t
readline(int sockfd, void *buf, size_t maxline)
{
	int ret;
	int nread;
	char *bufp = buf;
	int nleft = maxline;
	int count = 0;

	while (1)
	{
		ret = recv_peek(sockfd, bufp, nleft);
		if (ret <= 0)
		  return ret;

		nread = ret;
		int i;
		for (i = 0; i < nread; i++)
		{
			if (bufp[i] == '\n')
			{
				ret = readn(sockfd, bufp, i + 1);
				if (ret != i + 1)
				  exit(EXIT_FAILURE);

				return ret + count;
			}
		}

		if (nread > nleft)
		  exit(EXIT_FAILURE);
		nleft -= nread;
		ret = readn(sockfd, bufp, nread);
		if (ret != nread)
		  exit(EXIT_FAILURE);

		bufp += nread;
		count += nread;
	}

	return -1;
}
