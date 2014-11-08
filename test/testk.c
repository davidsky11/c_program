/*
 * =====================================================================================
 *
 *       Filename:  testk.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/08/2014 11:20:51 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	int i;
	int a[100];
} stu;

union
{
	int i;
	char a[2];
} *p, u;

void main()
{
	stu* pn = (stu *) malloc(sizeof(stu) + 100*sizeof(int));
	printf("%ld %ld\n", sizeof(stu), sizeof(*pn));
	free(pn);

	p = &u;
	p->a[0] = 0x01;
	p->a[1] = 0x02;
	printf("p.i = %d %d\n", p->i, (*p).i);
}
