/*
 * =====================================================================================
 *
 *       Filename:  testx86.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/08/2014 01:53:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int main()
{
	int a[5] = {1,2,3,4,5};
	int *ptr1 = (int *)(&a+1);
	int *ptr2 = (int *)(a+1);
	printf("%x, %x\n", ptr1[-1], *ptr2);
	return 0;
}
