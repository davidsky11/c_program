/*
 * =====================================================================================
 *
 *       Filename:  stack_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/29/2014 04:36:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int getInt()
{
	int i = 11;
	return i;
}

char *getStr()
{
	char *s = "abcdefgh";
	return s;
}

char[] getArray()
{
	char a[] = "mnopq";
	return a;
}

int
main(int argc, char *argv[])
{
	printf("%d\n", getInt());
	printf(" ----- %s ------\n", getStr());
	printf(" -/-/- %s -/-/-/\n", getArray());
}
