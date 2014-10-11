/*
 * =====================================================================================
 *
 *       Filename:  fifo_read.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/08/2014 04:28:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define WRITE_MAX 4096

#define FIFO_SERVER "/tmp/fifoserver"

int main(int argc, char *argv[]) {
	int fd;
	char r_buf[WRITE_MAX * 2];
	int r_size, ret_size, count = 0;
	r_size = atoi(argv[1]);

	printf("requred real read bytes %d\n", r_size);
	
	memset(r_buf, 0, sizeof(r_buf));

	fd = open(FIFO_SERVER, O_RDONLY|O_NONBLOCK, 0);

	if (fd == -1) {
		printf("open %s for read error\n", FIFO_SERVER);
		exit(EXIT_SUCCESS);
	}

	while (1) {
		memset(r_buf, 0, sizeof(r_buf));
		ret_size = read(fd, r_buf, r_size);
		if (ret_size == -1)
		  if (errno == EAGAIN)
			printf("no data avaliable\n");
		printf("real read bytes %d\n", ret_size);
		sleep(1);

		if (count ++ > 5)	break;
	}

	pause();
	unlink(FIFO_SERVER);
	exit(EXIT_SUCCESS);
}
