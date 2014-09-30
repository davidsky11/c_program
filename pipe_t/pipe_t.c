/*
 * =====================================================================================
 *
 *       Filename:  pipe_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/20/2014 08:41:15 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int pfd[2];
	int ret = pipe(pfd);

	if (ret != 0) {
		perror("pipe");
		exit(-1);
	}

	pid_t pid = fork();
	if (pid == 0) {
		close(pfd[1]);
		char rdbuf[1024];
		read(pfd[0], rdbuf, sizeof(rdbuf));
		return 0;
	} else if (pid > 0) {
		close(pfd[0]);
		char wrbuf[] = "abcd";
		write(pfd[1], wrbuf, sizeof(wrbuf));
		pid_t cpid = waitpid(-1, NULL, 0);
	} else {
		perror("fork");
	}

	return 0;
}
