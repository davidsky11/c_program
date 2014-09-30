/*
 * =====================================================================================
 *
 *       Filename:  point_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/24/2014 04:15:43 PM
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
	char *str3 = "test only: ";

	int str3_len = strlen(str3);
	int str2_len = strlen(str2);
	
	printf("%d %d\n", str3_len, str2_len);
	//str1 = str3[0];
	//*(str1 + str3_len) = str2;

	char *str = str1;	/* str is point to the begin of str1 pointeer. */
	int count = 0;
	int tmp = 0;
	do {
		if (count < str3_len - 1 ) {
			*str1++ = str3[count];
			printf("-\n");
		}
		else if (count == str3_len - 1) {
			*str1++ = str3[str3_len - 1];
			tmp = count;				;
			printf("=\n");
		}
		else {
			printf("%d %d %d\n", count, tmp, count-tmp-1);
			*str1++ = str2[count - tmp - 1];
			printf("+\n");
		}
	}
	while (count++ <= (str2_len + str3_len - 2));

	printf(" ==> %s \n", str);
	free(str);		/* str1 is point to the end. So, we can free str1 by str pointer */

	exit(EXIT_SUCCESS);
}
