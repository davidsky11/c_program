/*
 * =====================================================================================
 *
 *       Filename:  mem_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/22/2014 04:51:44 PM
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

struct student {
	char *name;
	int age;
}stu, *pstu;

int
main(int argc, char *argv[])
{
	pstu = (struct student *) malloc(sizeof(struct student));
	pstu->name = (char *) malloc(sizeof(char)); 
	strcpy(pstu->name, "KN");
	pstu->age = 19;
	free(pstu);

	return 0;
}
