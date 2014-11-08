/*
 * =====================================================================================
 *
 *       Filename:  testtypedef.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/08/2014 02:41:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

//typedef static int INT32;

//unsigned INT32 j = 10;

void main()
{
	char a[10] = {"abcdef"};

	printf("%s\n", a);

	int i;
	for (i = 0, printf("First=%d\n", i);
				i < 10/*  , printf("Second=%d\n", i)*/;
				i++, printf("Third=%d\n", i))
	{
		printf("Fourth=%d\n", i);
	}


}
