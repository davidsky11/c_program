/*
 * =====================================================================================
 *
 *       Filename:  parent_child_trans.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/14/2014 02:34:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../lib/tlpi_hdr.h"

#define BUF_SIZE  99

int TELL_WAIT();
int TELL_PARENT(int pid);
int WAIT_PARENT();
int TELL_CHILD(int pid);
int WAIT_CHILD();
char *toUpper(char *buf);

int c2p_pfd[2], p2c_pfd[2];
ssize_t numRead;
char buf[BUF_SIZE];
int pid;

int main(int argc, char *argv[])
{
	TELL_WAIT();

	switch (pid) {
		case -1:
			errExit("fork");

		case 0:
			sleep(3);
			if (close(p2c_pfd[1]) == -1)	/* Write end is unused */
			  errExit("close - p2c write");
			if (close(c2p_pfd[0]) == -1)	/* Read end is unused */
			  errExit("close - c2p read");

			for (;;) 
			{
				numRead= read(p2c_pfd[0], buf, BUF_SIZE);
				if (numRead == -1)
				  errExit("read");
				if (numRead == 0)
				  break;
			}

			printf("child get: %s\n", toUpper(buf));

			if (close(p2c_pfd[0]) == -1)
			  errExit("close 1");
			if (close(c2p_pfd[1]) == -1)
			  errExit("close 2");

			_exit(EXIT_SUCCESS);

		default:
			if (close(p2c_pfd[0]) == -1)	/* Read end is unused */
			  errExit("close - p2c read");
			if (close(c2p_pfd[1]) == -1)
			  errExit("close - c2p write");	/* Write end is unused */
			
			printf("origin input: %s\n", argv[1]);
			if (write(p2c_pfd[1], argv[1], strlen(argv[1])) != strlen(argv[1]))
			  errExit("write");

			if (close(p2c_pfd[1]) == -1)
			  errExit("close");
			wait(NULL);
			exit(EXIT_SUCCESS);
	}
}

int TELL_WAIT()
{
	if (pipe(c2p_pfd) == -1)
	  errExit("pipe c2p");

	if (pipe(p2c_pfd) == -1)
	  errExit("pipie p2c");

	pid = fork();
}

int TELL_PARENT(int pid)
{
	
}

int WAIT_PARENT()
{

}

int TELL_CHILD(int pid)
{

}

int WAIT_CHILD()
{

}

char *toUpper(char *s) 
{
	char *str = s;
	char *res = s;
	while (*s)
	  *str++ = toupper(*s++);

	return res;
}
