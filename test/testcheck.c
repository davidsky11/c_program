/*
 * =====================================================================================
 *
 *       Filename:  testcheck.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/08/2014 01:47:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int check()
{
	union check
	{
		int i;
		char ch;
	} c;
	c.i = 1;
	return (c.ch == 1);
}

void main()
{
	printf("is litter end? : %d\n", check());
}
