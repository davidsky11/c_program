/*
 * =====================================================================================
 *
 *       Filename:  sizeof_test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/09/2014 11:42:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int main() {
	int i;
	i = 10;
	printf("i : %d\n", i);
	printf("sizeof(i++) is : %d\n", sizeof(i++));
	printf("i : %d\n", i);
	return 0;
}
