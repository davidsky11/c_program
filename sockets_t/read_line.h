/*
 * =====================================================================================
 *
 *       Filename:  read_line.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 08:24:56 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef READ_LINE_H
#define READ_LINE_H

#include <sys/types.h>

ssize_t readLine(int fd, void *buffer, size_t n);

#endif
