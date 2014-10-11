/*
 * =====================================================================================
 *
 *       Filename:  print_int.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/09/2014 01:37:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>

#define SIZEOF(arr)		(sizeof(arr)/sizeof(arr[0]))
#define PrintInt(expr)	printf("%s:%d\n", #expr,(expr))

int main() {

	/* the number begin with '0' is octal number */
	int pot[] = {
		0001,
		0010,
		0100,
		1000
	};
	int i;
	for (i=0; i<SIZEOF(pot);i++)
	  PrintInt(pot[i]);

	return 0;
}
