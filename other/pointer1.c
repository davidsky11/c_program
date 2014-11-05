/*
 * =====================================================================================
 *
 *       Filename:  pointer1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/27/2014 03:18:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int pointer_addr()
{
	static int i = 10;
	static int j = 100;
	printf("%p %X\n", &i, &j);
}

int pointer_int()
{
	int i = 10;
	printf("%p\n", &i);
	int *p = (int *)(&i);
	*p = 0x100;
	printf("%p\n", &p);
	*p = NULL;
	p = NULL;
	printf("%p %d\n", &p, p);

	int *q = NULL;
	//q = NULL;
	printf("%p\n", &q);
}

int main()
{
	//pointer_addr();
	pointer_int();	
}
