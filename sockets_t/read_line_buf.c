/*
 * =====================================================================================
 *
 *       Filename:  read_line_buf.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/21/2014 04:37:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "read_line_buf.h"

void
readLineBufInit(int fd, struct readlinebuffer *rlbuf)
{
	rlbuf->fd = fd;
	rlbuf->size = 0;
	rlbuf->next = 0;
}

ssize_t
readLineBuf(struct readlinebuffer *rlbuf, char *buffer, size_t n)
{
	ssize_t totRead;
	char c;

	if (n <= 0 || buffer == NULL) 
	{
		errno = EINVAL;
		return -1;
	}

	totRead = 0;

	for (;;)
	{
		if (rlbuf->next >= rlbuf->size)
		{
			rlbuf->size = read(rlbuf->fd, rlbuf->buf, RL_MAX_BUF);
			if (rlbuf->size == -1)
			  return -1;

			if (rlbuf->size == 0)
			  break;

			rlbuf->next = 0;
		}


		c = rlbuf->buf[rlbuf->next];
		rlbuf->next++;

		if (totRead < n)
		  buffer[totRead++] = c;

		if (c == '\n')
		  break;
	}

	return totRead;
}
