/*
 * =====================================================================================
 *
 *       Filename:  testenum.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/08/2014 02:09:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

enum Color
{
	GREEN = 1,
	RED = 2,
	BLUE = 3,
	FREEN_READ = 10,
	GREEN_BLUE = 11
} ColorVal;

void main()
{
	printf("%ld %ld\n", sizeof(ColorVal), sizeof(int));
}
