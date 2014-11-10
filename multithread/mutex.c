/*
 * =====================================================================================
 *
 *       Filename:  mutex.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/10/2014 10:46:33 AM
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

#define THREAD_NUM		3
#define REPEAT_TIMES	5
#define DELAY			4

pthread_mutex_t mutex;

void *thread_func(void *arg);

int main()
{
	pthread_t thread[THREAD_NUM];
	int no;
	void *ret;

	srand((int)time(0));
	// 创建快速互斥锁（默认），锁的编号返回给mutex
	pthread_mutex_init(&mutex, NULL);

	// 创建THREAD_NUM个线程，每个线程号返回给&thread[no]，每个线程的入口函数均为thread_func，参数为no
	for (no = 0; no < THREAD_NUM; no++)
	{
		if (pthread_create(&thread[no], NULL, thread_func, (void *)no) != 0)
		{
			printf("Create thread %d error!\n", no);
			exit(1);
		}
		else
			printf("Create thread %d success!\n", no);
	}

	// 对每个线程进行join，返回值给ret
	for (no = 0; no < THREAD_NUM; no++)
	{
		if (pthread_join(thread[no], &ret) != 0)
		{
			printf("Join thread %d error!\n", no);
			exit(1);
		}
		else
			printf("Join thread %d success!\n", no);
	}

	// 消除互斥锁
	pthread_mutex_destroy(&mutex);
	return 0;
}

void *thread_func(void *arg)
{
	int thread_num = (int)arg;
	int delay_time, count;

	// 对互斥锁上锁
	if (pthread_mutex_lock(&mutex) != 0)
	{
		printf("Thread %d lock failed!\n", thread_num);
		pthread_exit(NULL);
	}

	printf("Thread %d is starting.\n", thread_num);
	for (count = 0; count < REPEAT_TIMES; count ++)
	{
		delay_time = (int) (DELAY *(rand()/(double)RAND_MAX)) + 1;
		sleep(delay_time);
		printf("\tThread %d:job %d delay =%d.\n", thread_num, count, delay_time);
	}

	printf("Thread %d is exiting.\n", thread_num);
	// 解锁
	pthread_mutex_unlock(&mutex);
	
	pthread_exit(NULL);
}
