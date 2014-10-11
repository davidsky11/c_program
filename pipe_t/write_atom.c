/*
 * =====================================================================================
 *
 *       Filename:  write_atom.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/08/2014 03:42:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define WRITE_MAX 5000		// > 4096

int main(int argc, char *argv[]) {
	int pipe_fd[2];
	pid_t pid;
	char r_buf[WRITE_MAX];
	char w_buf[WRITE_MAX * 2];
	int wnum, rnum, count = 0;

	memset(r_buf, 0, sizeof(r_buf));
	if (pipe(pipe_fd) < 0) {
		printf("pipe create error\n");
		return -1;
	}

	switch (pid = fork()) {
		case 0:
			close(pipe_fd[1]);
			while (1) {
				sleep(1);
				rnum = read(pipe_fd[0], r_buf, 1000);
				printf("child: readnum is %d\n", rnum);
				if (rnum == 0 && ++count == 3)	break;
			}
			close(pipe_fd[0]);
			_exit(EXIT_SUCCESS);

		case -1:
			break;

		default:
			close(pipe_fd[0]);
			memset(r_buf, 0, sizeof(r_buf));
			if ((wnum = write(pipe_fd[1], w_buf, 1024)) == -1)
			  printf("write to pipe error\n");
			else
			  printf("the bytes write to pipe is %d \n", wnum);

			wnum = write(pipe_fd[1], w_buf, 4096);
			close(pipe_fd[1]);
	}
				
}
