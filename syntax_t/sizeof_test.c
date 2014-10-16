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
	printf("sizeof(i++) is : %d\n", (int) sizeof(i++));
	printf("i : %d\n", i);
	
	int *p = NULL;
	printf("sizeof(*p) = %d, sizeof(p) = %d\n", (int) sizeof(*p), 
				(int) sizeof(p));

	int a[100];
	printf("sizeof(a) = %d, sizeof(a[100]) = %d\n", (int) sizeof(a),
				(int) sizeof(a[100]));

	printf("sizeof(&a) = %d, sizeof(&a[0]) = %d\n", (int) sizeof(&a), 
				(int) sizeof(&a[0]));

	return 0;
}
