/*
 * =====================================================================================
 *
 *       Filename:  sample_pipe.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/08/2014 11:08:15 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <sys/wait.h>
#include "../lib/tlpi_hdr.h"

#define BUF_SIZE 10

int main(int argc, char *argv[]) {
	int pfd[2];
	char buf[BUF_SIZE];
	ssize_t numRead;

	if (pipe(pfd) == -1) 
		errExit("pipe");

	switch (fork()) {
		case -1:
			errExit("fork");

		case 0:
			if (close(pfd[1]) == -1)
			  errExit("close - child");

			for (;;) {
				numRead = read(pfd[0], buf, BUF_SIZE);
				if (numRead == -1)
				  errExit("read");
				if (numRead == 0)
				  break;
				if (write(STDOUT_FILENO, buf, numRead) != numRead) 
				  fatal("child - partial/failed write");
			}

			write(STDOUT_FILENO, "\n", 1);
			if (close(pfd[0]) == -1)
			  errExit("close");
			_exit(EXIT_SUCCESS);

		default:
			if (close(pfd[0]) == -1)
			  errExit("close - parent");
			if (write(pfd[1], argv[1], strlen(argv[1])) != strlen(argv[1]))
			  fatal("parent - partial/failed write");

			if (close(pfd[1]) == -1)
			  errExit("close");
			wait(NULL);
			exit(EXIT_SUCCESS);
	}
}
