/*
 * =====================================================================================
 *
 *       Filename:  fs_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/15/2014 04:49:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), shiya.gang@163.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *show_t(char *, int);

struct file_t {
	char *name;
	int fs_flags;
	char *show (char *, int);
};

char *show_t(char *filename, int flags) {
	char *m;
	m = filename+flags;
	return m;
}

int main(int argc, char* argv[]) {
	struct file_t f;
	f.name= argv[1];
	f.fs_flags=atoi(argv[2]);
	f.show = show_t(f.name, f.fs_flags);
	printf(" ==> %s\n", f.show);
}
