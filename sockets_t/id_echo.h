/*
 * =====================================================================================
 *
 *       Filename:  id_echo.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 02:36:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "inet_sockets.h"
#include "../lib/tlpi_hdr.h"

#define SERVICE		"echo"		/* Name of UDP service */

#define BUF_SIZE	500			/* Maximum size of datagrams that can
									be read by client and server */
