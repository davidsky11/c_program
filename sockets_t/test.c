#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#include "read_line_buf.h"

int
main(int argc, char *argv[])
{
	char buf[512];
	int fd, numRead = 0, i;
	struct readlinebuffer *rlbuf;
	
	rlbuf = (struct readlinebuffer *) malloc(sizeof(struct readlinebuffer));
	//memset(&rlbuf, 0, sizeof(rlbuf));

	fd = open("/home/kevin/work/c_program/sockets_t/a", O_RDONLY, S_IRUSR | S_IRGRP);
	readLineBufInit(fd, rlbuf);

	numRead = readLineBuf(rlbuf, buf, sizeof(buf));
	printf("%s\n", buf);

	free(rlbuf);
	close(fd);
}


