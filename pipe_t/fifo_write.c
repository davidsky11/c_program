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
	char w_buf[WRITE_MAX * 2];
	int real_wnum;
	
	memset(w_buf, 0, WRITE_MAX * 2);

	if ((mkfifo(FIFO_SERVER,  O_CREAT|O_EXCL) < 0) && (errno != EEXIST))
	  printf("cannot create fifoserver\n");

	if (fd == -1)
	  if (errno == ENXIO)
		printf("open error; no reading process\n");

	fd = open(FIFO_SERVER, O_WRONLY|O_NONBLOCK, 0);
	real_wnum = write(fd, w_buf, 2048);
	if (real_wnum == -1) {
		if (errno == EAGAIN)
		  printf("write to fifo error; try later\n");
	}
	else
	  printf("real write num is %d\n", real_wnum);

	//real_wnum = write(fd, w_buf, 5000);		// 5000 use for non-atomicity of write operation
	real_wnum = write(fd, w_buf, 4096);		// 4096 use for atomicity of write operation

	if (real_wnum == -1)
	  if (errno == EAGAIN)
		printf("try later\n");
}
