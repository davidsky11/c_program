/*
 * =====================================================================================
 *
 *       Filename:  daemon.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/04/2014 10:48:24 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _DAEMON_H_
#define _DAEMON_H_

#include "config.h"
#include <syslog.h>
#include <string.h>

#define MAXFD 64

extern int daemon_flag;

int daemon_ser(const char *name, int facility);
void PST(char *ptr);

#endif
