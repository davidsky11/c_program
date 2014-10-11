/*
 * =====================================================================================
 *
 *       Filename:  mmap_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/09/2014 02:19:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <sys/mman.h>
#include <fcntl.h>
#include "../lib/tlpi_hdr.h"

#define MEM_SIZE 10

int main(int argc, char *argv[]) {
	int fd;
	char *addr;

	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	  errExit("open");

	addr = mmap(NULL, MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED)
	  errExit("mmap");

	if (close(fd) == -1)	/* No longer need 'fd' */
	  errExit("close");	

	printf("Current string=%.*s\n", MEM_SIZE, addr);
						/* Secure practice: output at most MEM_SIZE bytes */

	if (argc > 2) {
		if (strlen(argv[2]) > MEM_SIZE)
		  cmdLineErr("'new-value' too large\n");

		memset(addr, 0, MEM_SIZE);
		strncpy(addr, argv[2], MEM_SIZE - 1);
		if (msync(addr, MEM_SIZE, MS_SYNC) == -1)
		  errExit("msync");

		printf("Copied \"%s\" to shared memory\n", argv[2]);
	}

	exit(EXIT_SUCCESS);
}
