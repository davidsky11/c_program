/*
 * =====================================================================================
 *
 *       Filename:  mmap_anon.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/09/2014 02:31:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifdef USE_MAP_ANON
#define _BSD_SOURCE
#endif

#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "../lib/tlpi_hdr.h"

int main(int argc, char *argv[]) {
	int *addr;

#ifdef USE_MAP_ANON
	addr = mmap(NULL, sizeof(int), PROT_READ| PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (addr == MAP_FAILED)
	  errExit("mmap");

#else
	int fd;

	fd = open("/dev/zero", O_RDWR);
	if (fd == -1)
	  errExit("open");

	addr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED)
	  errExit("mmap");

	if (close(fd) == -1)
	  errExit("close");
#endif

	*addr = 1;

	switch (fork()) {
		case -1:
			errExit("fork");

		case 0:
			printf("Child started, value = %d\n", *addr);
			(*addr)++;

			if (munmap(addr, sizeof(int)) == -1)
			  errExit("nunmap");
			exit(EXIT_SUCCESS);

		default:
			if (wait(NULL) == -1)
			  errExit("wait");
			printf("In parent, value = %d\n", *addr);
			if (munmap(addr, sizeof(int)) == -1)
			  errExit("nunmap");
			exit(EXIT_SUCCESS);
	}
}
