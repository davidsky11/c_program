/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/08/2014 10:30:19 AM
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

#define MN 11

const int M = 1;
const int N = 2;
const int Max = 100;

int getNum();

void main(int argc, char *argv[])
{	
/*	switch (atoi(argv[1]))
	{
		case (M):
			printf("M\n");
			break;

		case (N):
			printf("N\n");
			break;

		default:
			break;
	}
*/
	
	int Array[Max];
	Array[0] = 0;
	printf("%d %d\n", getNum(), Array[0]);

	int i = M;
	int j = M;
	printf("%p ----- %p ------ %p\n", &i, &j, &N);

	printf("______________________\n");
	int k = MN;
	printf("%p ----- %p\n", &k, MN);
	int c = MN;
	printf("%p ----- %p\n", &c, MN);
}


int getNum()
{
	return;
}
