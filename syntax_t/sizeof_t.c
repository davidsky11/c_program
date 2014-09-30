/*
 * =====================================================================================
 *
 *       Filename:  example_code.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/2014 10:40:08 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>

struct X {
	int a;
	int b;
	char c;
} x;

struct Y {
	double a;	// 8 bytes
	int b;		// 4 bytes
	short c;	// 2 bytes
	char d;		// 1 bytes
} y;

struct Z {
	int a;
	double b;
	short c;
	char d;
} z;

struct M {
	double a;
	short b;
	char d;
} m;

void foo(void) {
	unsigned int a = 6;
	int b = -20;
	printf("(a+b)=%x\n", (a+b));
	(a+b > 6) ? puts(">6") : puts("<=6");
}

void main(void) {
//	foo();

	unsigned int ui = -20;
	printf("%x %d %d\n", ui, ui, (int) sizeof(ui));
		
	char a[20] = "rock";
	printf(" a ==> %d ,%d \n", (int) sizeof(a), (int) strlen(a));

	char b[] = "test";
	printf(" b ==> %d, %d\n", (int) sizeof(b), (int) strlen(b));

	char c[2] = "test";
	printf(" c ==> %d, %d\n", (int) sizeof(c), (int) strlen(c));

	char* ss = "0123456789";
	printf(" %d %d %d\n", (int) sizeof(ss), (int) sizeof(*ss), (int) strlen(ss));

	int n = 123;
	int *m;
	m = &n;
	printf(" %d \n", (int) sizeof(m));

	printf("%d %d %d %d\n", (int) sizeof(struct X), (int) sizeof(struct Y), (int) sizeof(struct Z), (int) sizeof(struct M));
	printf("%d %d %d\n", (int) sizeof(x), (int) sizeof(y), (int) sizeof(z));
}

