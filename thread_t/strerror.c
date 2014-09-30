/*
 * =====================================================================================
 *
 *       Filename:  strerror.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/29/2014 09:55:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#define MAX_ERROR_LEN 256

static char buf[MAX_ERROR_LEN];

char *strerror(int err) {
	if (err < 0 || err >= _sys_nerr || _sys_errlist[err] == NULL) {
		snprintf(buf, MAX_ERROR_LEN, "Unkonwn error %d", err);
	} else {
		strncpy(buf, _sys_errlist[err], MAX_ERROR_LEN - 1);
		buf[MAX_ERROR_LEN - 1] = '\0';
	}

	return buf;
}
