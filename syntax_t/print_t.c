/*
 * =====================================================================================
 *
 *       Filename:  print_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/16/2014 01:41:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), shiya.gang@163.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int height = 3;
	int width = 4;
	printf("%2$*1$d\n", height, width);
	printf("%'.2f\n", 1234567.89);
	fprintf(stdout, "pi = %.5f\n", 4 * atan(1.0));
}
