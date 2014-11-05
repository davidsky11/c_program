/*
 * =====================================================================================
 *
 *       Filename:  stringcat.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/27/2014 02:27:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void string_cat(char *dest, char *src)
{
	char *p = dest;
	while (*dest++);
	dest--;
	while (*dest++ = *src++);
	*dest = '\0';
	dest = p;
}

int main()
{
	char *dest = "helo ";
	char *tnt = "monk";
	string_cat(dest, tnt);
	printf("%s\n", dest);
}
