/*
 * =====================================================================================
 *
 *       Filename:  thread_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/20/2014 08:30:45 AM
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
#include <pthread.h>

struct member {
	int num;
	char *name;
};

void *create(void *arg) {
	struct member *temp;
	temp = (struct member *)arg;
	printf("member->num: %d\n", temp->num);
	printf("member->char: %s\n", temp->name);
	
	sleep(1);
	return (void *)8;
}

int main(int argc, char * argv[]) {
	pthread_t tidp;
	struct member *b;
	void *a;
	b = (struct member *) malloc(sizeof(struct member));
	b->num = 1;
	b->name = "test";

	if ((pthread_create(&tidp, NULL, create, (void *)b)) == -1) {
		printf("create error!\n");
		return 1;
	}

	if (pthread_join(tidp, &a)) {
		printf("thread is not exit...\n");
		return -2;
	}

	printf("thread is exit, code is %d\n", (int) a);
	return 0;
}

