/*
 * =====================================================================================
 *
 *       Filename:  svmsg_ls.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/16/2014 03:50:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/msg.h>
#include "../lib/tlpi_hdr.h"

int
main(int argc, char *argv[])
{
	int maxind, ind, msqid;
	struct msqid_ds ds;
	struct msginfo info;

	/* Obtain size of kernel 'entries' array */

	maxind = msgctl(0, MSG_INFO, (struct msqid_ds *) &info);
	if (maxind == -1)
	  errExit("msgctl");

	printf("maxind: %d\n\n", maxind);
	printf("index	 id	key 		messages\n");

	/* Retrieve and display information from each element of 'entries' array */

	for (ind = 0; ind <= maxind; ind++)
	{
		msqid = msgctl(ind, MSG_STAT, &ds);
		if (msqid == -1)
		{
			if (errno != EINTR && errno != EACCES)
			  errMsg("msgctl-MSG_STAT");	/* Unexpected error */
			continue;						/* Ignore this item */
		}

		printf("%4d %8d	0x%08lx %7ld\n", ind, msqid,
					(unsigned long) ds.msg_perm.__key, (long) ds.msg_qnum);
	}

	exit(EXIT_SUCCESS);
}
