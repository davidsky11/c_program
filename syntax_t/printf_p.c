/*
 * =====================================================================================
 *
 *       Filename:  printf_p.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/09/2014 11:30:20 AM
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
	float a = 12.5;
	printf("%d\n", a);
	printf("%d\n", (int) a);
	printf("%d\n", *(int *) &a);
	return 0;
}
