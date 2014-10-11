/*
 * =====================================================================================
 *
 *       Filename:  write_dependency.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/08/2014 02:01:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int pipe_fd[2];
	pid_t pid;
	char r_buf[4];
	char *w_buf;
	int writenum, cmd;

	memset(r_buf, 0, sizeof(r_buf));
	if (pipe(pipe_fd) < 0) {
		printf("pipe create error\n");
		return -1;
	}

	switch (pid = fork()) {
		case -1:
			printf("pipe create error\n");
			return -1;

		case 0:
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			printf("child process\n");
			sleep(3);
			_exit(EXIT_SUCCESS);

		default:
			sleep(1);	// wait for child process close the read end
			printf("parent process\n");
			close(pipe_fd[0]);	// write
			w_buf = "121";
			if ((writenum = write(pipe_fd[1], w_buf, 4)) == -1)
			  printf("write to pipe error\n");
			else
			  printf("the bytes write to pipe is %d \n", writenum);

			close(pipe_fd[1]);
	}
}
