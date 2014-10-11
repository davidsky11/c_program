/*
 * =====================================================================================
 *
 *       Filename:  printf_more.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/09/2014 11:27:45 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
	int i = 43;
	printf("%d\n", printf("%d", printf("%d", i)));
	return 0;
}
