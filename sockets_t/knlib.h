/*
 * =====================================================================================
 *
 *       Filename:  knlib.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/22/2014 08:50:16 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef KNLIB_H
#define KNLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BACKLOG		1024
#define MAXLINE		1280
#define SERV_PORT	14536

typedef void (*SignalFunc) (int);

SignalFunc signal_k(int sigNo, SignalFunc fun);
void sig_chld(int sigNo);

#endif
