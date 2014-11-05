/*
 * =====================================================================================
 *
 *       Filename:  poin_size1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/28/2014 10:44:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

void main(void)
{
	int a[5] = {1, 2, 3, 4, 5};

	int *ptr = (int *)(&a + 1);
	
	printf("%d, %d\n", *(a+1), *(ptr-1));	
}
