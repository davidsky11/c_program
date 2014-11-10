/*
 * =====================================================================================
 *
 *       Filename:  test_memalign.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/08/2014 04:00:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#pragma pack(4)
struct TestStruct
{
	char c1;
	char c2;
	char c3;
	short s;
	int i;
};
#pragma pack()

void main()
{
	struct TestStruct a;
	printf("c1 %p, s %p, c2 %p, i %p\n",
				(unsigned int)(void*)&a.c1 - (unsigned int)(void*)&a,
				(unsigned int)(void*)&a.s - (unsigned int)(void*)&a,
				(unsigned int)(void*)&a.c2 - (unsigned int)(void*)&a,
				(unsigned int)(void*)&a.i - (unsigned int)(void*)&a);
	printf("%ld\n", sizeof(a));
	long int k = 1L;
	int l = 0;
	printf("%ld %ld\n", sizeof(k), sizeof(l));
}
