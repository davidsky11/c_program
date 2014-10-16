/*
 * =====================================================================================
 *
 *       Filename:  case_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/13/2014 01:35:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int 
main(int argc, char *argv[]) 
{
	int m = 'C';

	if (argc < 2)
	  return;

	m = atoi(argv[1]);
	printf(" m: %d\n", m);

	switch (m)
	{
		case -1:
			printf("-1\n");
			break;

		case 'A':
			printf("A\n");
			break;

		case 'A'+1:
			printf("B\n");
			break;

		//case 0.1+0.9:
		//	printf("0.1+0.9\n");

		//case NULL:
		//	printf("NULL\n");

		default:
			printf(" default =>  %d\n", m);
			break;
	}

	return 0;
}
