/*
 * =====================================================================================
 *
 *       Filename:  poin_size.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/28/2014 10:30:44 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>

void  main(void)
{
	char *a = NULL;
	char *s = "abcdefghijk";
	a = s;
	char *ptr = (char *)&a;
	printf("%s, %c, %c\n", a, *(a+1), *(*(*ptr)));
}
