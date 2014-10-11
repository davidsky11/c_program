/*
 * =====================================================================================
 *
 *       Filename:  readtest.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/08/2014 01:41:44 PM
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
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int pipe_fd[2];
	pid_t pid;
	char r_buf[100];
	char w_buf[4];
	char *p_wbuf;
	int r_num;
	int cmd;

	memset(r_buf, 0, sizeof(r_buf));
	memset(w_buf, 0, sizeof(w_buf));
	p_wbuf = w_buf;

	if (pipe(pipe_fd) < 0) {
		printf("pipe create error\n");
		return -1;
	}

	if ((pid = fork()) == 0) {
		printf("\n");
		close(pipe_fd[1]);
		sleep(3);		// ensure the write end of parent process has been closed
		r_num = read(pipe_fd[0], r_buf, 100);
		printf("read num is %d  the data read from the pipe is %d\n", r_num, atoi(r_buf));

		close(pipe_fd[0]);
		exit(EXIT_SUCCESS);
	}
	else if (pid > 0) {
		close(pipe_fd[0]);	// read end
		strcpy(w_buf, "121");
		if (write(pipe_fd[1], w_buf, 4) != -1)
		  printf("parent write over\n");
		close(pipe_fd[1]);
		printf("parent close fd[1] over\n");
		sleep(10);
	}
}
