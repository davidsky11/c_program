/*
 * =====================================================================================
 *
 *       Filename:  datasize.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/08/2014 04:30:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

void main()
{
	void *p = NULL;
	printf("%ld\n", sizeof((short)1));
	printf("%ld\n", sizeof((int)1));
	printf("%ld\n", sizeof((long int)1));
	printf("%ld\n", sizeof((float)1));
	printf("%ld\n", sizeof((double)1));
	printf("%ld\n", sizeof((char)1));
	printf("%ld\n", sizeof(p));
}
