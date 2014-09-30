/*
 * =====================================================================================
 *
 *       Filename:  curr_time.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/20/2014 10:58:39 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

/* curr_time.c
 *
 * Implement our currTime() function.
 */

#include <time.h>
#include "curr_time.h"

#define BUF_SIZE 1000

char *
currTime(const char *format)
{
	static char buf[BUF_SIZE];
	time_t t;
	size_t s;
	struct tm *tm;

	t = time(NULL);
	tm = localtime(&t);
	if (tm == NULL)
	  return NULL;

	s = strftime(buf, BUF_SIZE, (format != NULL) ? format : "%c", tm);

	return (s == 0) ? NULL : buf;
}
