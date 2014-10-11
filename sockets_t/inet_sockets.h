/*
 * =====================================================================================
 *
 *       Filename:  inet_sockets.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 01:26:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef INET_SOCKETS_H
#define INET_SOCKETS_H

#include <sys/socket.h>
#include <netdb.h>

int inetConnect(const char *host, const char *service, int type);

int inetListen(const char *service, int backlog, socklen_t *addrlen);

int inetBind(const char *service, int type, socklen_t *addrlen);

char *inetAddressStr(const struct sockaddr *addr, socklen_t addrlen, 
			char *addrStr, int addrStrLen);

#define IS_ADDR_STR_LEN  4096
				/* Suggested length for string buffer that caller
				 * should pass to inetAddressStr(). Must be greater
				 * than (NI_MAXHOST _ NI_MAXSERV + 4) */

#endif
