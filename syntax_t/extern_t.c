/*
 * =====================================================================================
 *
 *       Filename:  extern_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/16/2014 04:46:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

extern int global = 11;
extern void shareData();

void shareData() {
	int cc = global;
	printf("%d\n", cc);
}
