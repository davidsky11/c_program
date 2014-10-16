/*
 * =====================================================================================
 *
 *       Filename:  static_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/13/2014 09:08:49 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

static int j;
int i;

void fun1(void) {
	static int i = 0;
	i++;
	printf("i = %d\t", i);
}

void fun2(void) {
	j = 0;
	j++;
	printf("j = %d\n", j);
}

int main() {
	int k;
	for (k=0; k<10; k++) {
		fun1();
		fun2();
	}

	return 0;
}
