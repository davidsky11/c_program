/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/07/2014 02:20:00 PM
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
#include "reciprocal.hpp"

int main(int argc, char *argv[])
{
	int i;

	i = atoi(argv[1]);
	printf("The reciprocal of %d id %g\n", i, reciprocal(i));
	return 0;
}
