/*
 * =====================================================================================
 *
 *       Filename:  parent_to_child_signal.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/15/2014 09:46:18 AM
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

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#include "../lib/tlpi_hdr.h"

#define BUF_SIZE  1024

char *toUpper_p(char *s);
char *toUpper_a(char s[]);

int main(int argc, char *argv[])
{
	pid_t pid;
	int shmid;
	char *shm_addr;
	char flag[] = "Parent";
	char buff[BUF_SIZE];

	/* 创建当前进程的私有共享内存 */
	if ((shmid = shmget(IPC_PRIVATE, BUF_SIZE, 0666)) < 0)
	  errExit("shmget");
	else
	  printf("Create shared memory: %d.\n", shmid);
	
	/* ipcs 命令往标准输出写入一些关于活动进程间通信设施的信息
	 * -m 表示共享内存 */
	printf("Created shared memory status: \n");
	system("ipcs -m");

	switch (pid = fork()) 
	{
		case -1:
			errExit("fork");

		case 0:
			/* 自动分配共享内存映射地址，为可读可写，
			 * 映射地址返回给shm_addr */
			if ((shm_addr = shmat(shmid, 0, 0)) == (void*) -1)
			  errExit("Child: shmat");
			else
			  printf("Child: Attach shared-memory: %p.\n", shm_addr);

			printf("Child Attach shared memory status: \n");
			system("ipcs -m");

			/* 比较shm_addr, flag 的长度为strlen(flag) 的字符
			 * 当其内容相同时，返回0, 否则返回(str1[n] - str2[n]) */
			while (strncmp(shm_addr, flag, strlen(flag)))
			{
				printf("Child: Waiting for data...\n");
				sleep(1);
			}

			strcpy(buff, shm_addr + strlen(flag));
			printf("Child: Shared-memory: -- %s\n", toUpper_p(buff));

			/* 删除子进程的共享内存映射地址 */
			if (shmdt(shm_addr) < 0)
			  errExit("Child: shmdt");
			else
			  printf("Child: Deattach shared-memory.\n");

			printf("Child: Deattach shared memory status:\n");
			system("ipcs -m");
			break;

		default:
			sleep(1);
			/* 自动分配共享内存映射地址，为可读可写，
			 * 映射地址返回给shm_addr */
			if ((shm_addr = shmat(shmid, 0, 0)) == (void*)-1)
			  errExit("Parent:shmat");
			else
			  printf("Parent: Attach shared-memory: %p.\n", shm_addr);

			printf("Parent Attach shared memory status:\n");
			system("ipcs -m");

			sleep(1);
			//printf("\nInput string:\n");
			//fgets(buff, BUF_SIZE - strlen(flag), stdin);
			//sleep(2);

			//buff = (argc > 1) ? argv[1] : "Hello World";
			//buff = argv[1];
			//strncpy(shm_addr + strlen(flag), buff, strlen(buff));

			/* shm_addr 为 flag + stdin 或 falg + argv[1] */
			printf("==> %s\n", argv[1]);
			strncpy(shm_addr + strlen(flag), argv[1], strlen(argv[1]));
			strncpy(shm_addr, flag, strlen(flag));

			/* 删除父进程的共享内存映射地址 */
			if (shmdt(shm_addr) < 0)
			  errExit("Parent: shmdt");
			else
			  printf("Parent: Deattach shared-memory.\n");

			printf("Parent Deattach shared-memory status:\n");
			system("ipcs -m");

			/* 保证父进程在删除共享内存前，子进程能读到共享内存的内容 */
			waitpid(pid, NULL, 0);

			/* 删除共享内存 */
			if (shmctl(shmid, IPC_RMID, NULL) == -1)
			  errExit("shmct: IPC_RMID");
			else
			  printf("Delete shared-memory.\n");

			printf("Child Delete shared memory status:\n");
			system("ipcs -m");

			printf("Finished!\n");
			break;
	}

	exit(EXIT_SUCCESS);
}

char *toUpper_p(char *s)
{
	char *str = s;
	char *res = s;
	while (*s)
	  *str++ = toupper(*s++);

	return res;
}

char *toUpper_a(char s[])
{
	char *res = s;
	int i, size = strlen(s);

	for (i=0; i<size; i++)
	{
		s[i] = toupper(s[i]);
	}

	return res;
}
