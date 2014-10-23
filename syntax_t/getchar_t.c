/*
 * =====================================================================================
 *
 *       Filename:  getchar_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/23/2014 10:25:46 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int
main(void)
{
	int i;
	while ((i = getchar()) != EOF)
	{
		putchar(i);
	}

	return 0;
}
