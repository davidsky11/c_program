/*
 * =====================================================================================
 *
 *       Filename:  fork_stdio_buf.c
 *
 *    Description:  ./fork_stdio_buf
 *					./fork_stdio_buf > out
 *
 *        Version:  1.0
 *        Created:  09/23/2014 09:04:13 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#define _BSD_SOURCE
#include "../lib/tlpi_hdr.h"

#define EXIT_BUG	"bug"
#define EXIT_FFLUSH	"fflush"
#define EXIT_SETBUF	"setbuf"
#define EXIT__EXIT	"_exit"

int main(int argc, char *argv[]) {

	if (argc < 2)  
	  errExit("argument unmatch.\n");

	
	if (strcmp(argv[1], EXIT_BUG) == 0) {
		printf("Hello BUG\n");
		write(STDOUT_FILENO, "Ciao\n", 5);

		if (fork() == -1)
			errExit("fork");

		/* Both child and parent continue execution here */
		exit(EXIT_SUCCESS);
	} else if (strcmp(argv[1], EXIT_FFLUSH) == 0) {
		printf("Hello FFLUSH\n");
		fflush(stdout);

		write(STDOUT_FILENO, "Ciao\n", 5);

		if (fork() == -1)	errExit("fork");
		
		/* Both child and parent continue execution here */
		exit(EXIT_SUCCESS);
	} else if (strcmp(argv[1], EXIT_SETBUF) == 0) {
		printf("Hello SETBUF\n");
		
		if (setvbuf(stdout, NULL, _IONBF, 0) != 0)	/* fflush I/O buffer */
		  errExit("setvbuf");
		
		write(STDOUT_FILENO, "Ciao\n", 5);

		if (fork() == -1)	errExit("fork");

		/* Both child and parent continue execution here */				
		exit(EXIT_SUCCESS);
	} else if (strcmp(argv[1], EXIT__EXIT) == 0) {
		printf("Hello _EXIT\n");
		write(STDOUT_FILENO, "ciao\n", 5);

		pid_t pid = fork();
		if (pid == -1)	errExit("fork");
		else if (pid == 0) {
			printf("child process\n");
			_exit(EXIT_SUCCESS);
		}

		/* Both child and parent continue execution here */
		exit(EXIT_SUCCESS);
	} else {
		printf("Please input the suitable arguments\n");
	}
}
