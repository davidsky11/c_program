/*
 * =====================================================================================
 *
 *       Filename:  testmacro.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/08/2014 03:43:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#define X 3
#define Y X*2
#undef X
#define X 2

#define EMPTY
#define SUM(x)  (x) + (x)

void main()
{
	printf("SUM(x)");
	printf("\n");
	int z = Y;
	printf("%d\n", z);
}
