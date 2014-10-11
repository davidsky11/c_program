/*
 * =====================================================================================
 *
 *       Filename:  mmcat.c
 *
 *    Description:  a sample to cat file content.
 *					$ ./mmcat tnt
 *
 *        Version:  1.0
 *        Created:  10/09/2014 02:08:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../lib/tlpi_hdr.h"

int main(int argc, char *argv[]) {
	char *addr;
	int fd;
	struct stat sb;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	  errExit("open");


	/* Obtain the size of the file and use it to specify the size of 
	 * the mapping and the size of the buffer to be between */

	if (fstat(fd, &sb) == -1)
	  errExit("fstat");

	addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (addr == MAP_FAILED)
	  errExit("mmap");

	if (write(STDOUT_FILENO, addr, sb.st_size) != sb.st_size)
	  fatal("partial/failed write");

	exit(EXIT_SUCCESS);
}
