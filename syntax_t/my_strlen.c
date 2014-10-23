/*
 * =====================================================================================
 *
 *       Filename:  my_strlen.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/23/2014 10:40:45 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <assert.h>
#include <stdio.h>

int
my_strlen(const char *strDest)
{
	assert(NULL != strDest);
	return ('\0' != *strDest) ? (1 + my_strlen(strDest + 1)) : 0;
}

int 
main(int argc, char *argv[])
{
	char *str = NULL;
	if (argc > 1)
	  str = argv[1];
	printf("%d\n", my_strlen(str));
}
