/*
 * =====================================================================================
 *
 *       Filename:  execve_t.c
 *
 *    Description:  ./execve ./envargs		-- TO RUN IT. 
 *
 *        Version:  1.0
 *        Created:  09/24/2014 03:12:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "../lib/tlpi_hdr.h"

int main(int argc, char *argv[]) {
	char *argVec[10];
	char *envVec[] = { "GREET=salut", "BYE=adieu", NULL };

	argVec[0] = strrchr(argv[1], '/');
	if (argVec[0] != NULL)
	  argVec[0]++;
	else
	  argV[0] = argv[1];

	argVec[1] = "hello world";
	argVec[2] = "goodbye";
	argVec[3] = NULL;

	execve(argv[1], argVec, envVec);
	errExit("execve");
}
