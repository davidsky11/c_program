/*
 * =====================================================================================
 *
 *       Filename:  file_server.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/20/2014 03:10:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>

#include "../lib/tlpi_hdr.h"

#define BACKLOG	11

#define FILE_NAME_MAX_SIZE	128

#define FILE_EXIST	TRUE
#define FILE_NONEXIST	FALSE

#define BUF_SIZE	512

#define TRANS_PORT	50012

#define CLIENT_PORT	48960

#define NOT_FOUND	"404"
