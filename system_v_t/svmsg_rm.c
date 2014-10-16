/*
 * =====================================================================================
 *
 *       Filename:  svmsg_rm.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/16/2014 03:31:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <sys/types.h>
#include <sys/msg.h>
#include "../lib/tlpi_hdr.h"

int
main(int argc, char *argv[])
{
	int j;
	if (argc > 1 && strcmp(argv[1], "--help") == 0)
	  usageErr("%s [msqid...]\n", argv[0]);

	for (j = 0; j < argc; j++)
	  if (msgctl(getInt(argv[j], 0, "msqid"), IPC_RMID, NULL) == -1)
		errExit("msgctl");

	exit(EXIT_SUCCESS);
}
