/*
 * =====================================================================================
 *
 *       Filename:  read_lien_buf.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/21/2014 04:29:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef READ_LINE_BUF_H
#define READ_LINE_BUF_H

#include <unistd.h>
#include <errno.h>

#define RL_MAX_BUF	10

struct readlinebuffer {
	int fd;						/* File descriptor from which to read */
	char buf[RL_MAX_BUF];		/* Current buffer from file */
	ssize_t size;				/* Index of next unread character in 'buf' */
	int next;					/* Number of characters in 'buf' */
};

void readLineBufInit(int fd, struct readlinebuffer *rlbuf);
ssize_t readLineBuf(struct readlinebuffer *rlbuf, char *buf, size_t n);

#endif
