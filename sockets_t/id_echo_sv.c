/*
 * =====================================================================================
 *
 *       Filename:  id_echo_sv.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 02:38:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <syslog.h>
#include "id_echo.h"
#include "../daemons/become_daemon.h"

int 
main(int argc, char *argv[])
{
	int sfd;
	ssize_t numRead;
	socklen_t len;
	struct sockaddr_storage claddr;
	char buf[BUF_SIZE];
	char addrStr[IS_ADDR_STR_LEN];

	if (becomeDaemon(0) == -1)
	  errExit("becomeDaemon");

	sfd = inetBind(SERVICE, SOCK_DGRAM, NULL);
	if (sfd == -1) {
		syslog(LOG_ERR, "Could not create server socket (%s)", strerror(errno));
		exit(EXIT_FAILURE);
	}

	/* Receive datagrams and return copies to senders */

	for (;;) {
		len = sizeof(struct sockaddr_storage);
		numRead = recvfrom(sfd, buf, BUF_SIZE, 0,
					(struct sockaddr *) &claddr, &len);
		if (numRead == -1)
		  errExit("recvfrom");

		if (sendto(sfd, buf, numRead, 0, (struct sockaddr *) &claddr, len)
					!= numRead)
		  syslog(LOG_WARNING, "Error echoing response to %s (%s)",
					  inetAddressStr((struct sockaddr *) &claddr, len,
						  addrStr, IS_ADDR_STR_LEN),
					  strerror(errno));
	}
}
