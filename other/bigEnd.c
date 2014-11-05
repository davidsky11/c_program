/*
 * =====================================================================================
 *
 *       Filename:  bigEnd.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/27/2014 02:15:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#define BIG_END		1
#define LITTLE_END	-1

#include <stdio.h>
#include <string.h>

int isBigEnd1()
{
	short int a = 0x1234;
	char b = *(char *) &a;
	if (b == 0x12)
	  return BIG_END;
	else
	  return LITTLE_END;
}

int isBigEnd2()
{
	union w
	{
		int a;
		char b;
	} c;
	c.a = 1;

	if (c.b == 1)
	  return BIG_END;
	else
	  return LITTLE_END;
}


int 
main(int argc, char *argv[])
{
	if (strcpy(argv[1], "1"))
	  printf("is Big End True: %d\n", isBigEnd1());
	else if (strcpy(argv[1], "2"))
	  printf("is Big End True: %d\n", isBigEnd2());
}
