/*
 * =====================================================================================
 *
 *       Filename:  logic_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/09/2014 01:47:06 PM
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
	int i = 6;
	if (((++i<7) && (i++/6)) || (++i<=9))
	  ;

	printf("%d\n", i);
	return 0;
}
