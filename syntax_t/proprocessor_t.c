/*
 * =====================================================================================
 *
 *       Filename:  proprocessor_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/2014 02:28:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#define UL (unsigned long)
#define SECONDS_PER_YEAR	UL(60 * 60 * 24 * 365)

void main(void) {
	printf("%ld\n", (long) SECONDS_PER_YEAR);
}
