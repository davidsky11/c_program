/*
 * =====================================================================================
 *
 *       Filename:  point_t_2.c
 *
 *    Description:  use the pointer to implement function 'strcat' 
 *
 *        Version:  1.0
 *        Created:  09/26/2014 04:15:43 PM
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
#include <string.h>

int main(int argc, char *argv[]) {
	char *str1 ;
	str1 = (char *)malloc(sizeof(char) * 100);
	char *str2 = "y/n";
//	char *str3 = "test only: ";			/* 1 */
	char strm[12] = "test onlt: ";		/* 2 */
	char *str3;
	str3 = strm;
		
	char *str = str1;		/* point to the begin of str1 */

	while (*str3 || *str2) {	/* use the feature of '||' */
		if (*str3)
		  *str1++ = *str3++;
		else if (*str2)
		  *str1++ = *str2++;
	}

	printf(" ==> %s \n", str);
	free(str);

	exit(EXIT_SUCCESS);
}
