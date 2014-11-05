/*
 * =====================================================================================
 *
 *       Filename:  work.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/04/2014 08:56:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _WORK_H_
#define _WORK_H_

//#define DEBUG

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#include "daemon.h"
#include "config.h"

void serve_machine(int *connfd);		/* 为客户端服务函数 */
void send_to_server(FILE *client_sock, char *path);

#endif
