/*
 * =====================================================================================
 *
 *       Filename:  read_write.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/01/2014 02:04:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

ssize_t recv_peek(int, void *, size_t);

ssize_t readline(int, void *, size_t);

