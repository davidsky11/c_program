/*
 * =====================================================================================
 *
 *       Filename:  poll_pipes.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/31/2014 03:25:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <time.h>
#include <poll.h>
#include "../lib/tlpi_hdr.h"

int
main(int argc, char *argv[])
{
	int numPipes, j, ready, randPipe, numWrites;
	int (*pfds)[2];			/* File descriptions for all pipes */
	struct pollfd *pollFd;

	/* Allocate the arrays that we use. The arrays are sized according
	 * to the number of pipes specified on command line */
	numPipes = getInt(argv[1], GN_GT_O, "num-pipes");

	pfds = calloc(numPipes, sizeof(int [2]));
	if (pfds == NULL)
	  errExit("calloc");
	pollFd = calloc(numPipes, sizeof(struct pollfd));
	if (pollFd == NULL)
	  errExit("calloc");

	/* Create the number of pipes specified on command line */
	for (j = 0; j < numPipes; j++)
	  if (pipe(pfds[j]) == -1)
		errExit("pipe %d", j);

	/* Perform specified number of writes to random pipes */
	numWrites = (argc > 2) ? getInt(argv[2], GN_GT_O, "num-writes") : 1;
	srandom((int)time(NULL));
	for (j = 0; j < numWrites; j++)
	{
		randPipe = random() % numPipes;
		printf("Writing to fd: %3d (read fd: %3d)\n",
					pfds[randPipe][1], pfds[randPipe][0]);
		if (write(pfds[randPipe][1], "a", 1) == -1)
		  errExit("write %d", pfds[randPipe][1]);
	}

	/* Build the file descriptor list to be supplied to poll(). This list
	 * is set to contain the file descriptors for the read ends of all of 
	 * the pipes. */
	for (j = 0; j < numPipes; j++)
	{
		pollFd[j].fd = pfds[j][0];
		pollFd[j].events = POLLIN;
	}

	ready = poll(pollFd, numPipes, -1);		/* Nonblocking */
	if (ready == -1)
	  errExit("poll");

	printf("poll() returned: %d\n", ready);

	/* Check which pipes have data available for reading */
	for (j = 0; j < numPipes; j++)
	  if (pollFd[j].events & POLLIN)
		printf("Readable: %d %3d\n", j, pollFd[j].fd);

	exit(EXIT_SUCCESS);
}
