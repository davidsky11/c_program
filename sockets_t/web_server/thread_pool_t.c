/*
 * =====================================================================================
 *
 *       Filename:  thread_poll_t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/01/2014 05:13:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#define _GNU_SOURCE

#include "thread_pool_t.h"

thread_pool *pool;
extern int daemon_flag;

/*
 * 初始化线程池
 */
int 
initial_thread_pool(int num)
{
	pthread_attr_t attr;
	pthread_t pid;
	int i, err;
	pool = (thread_pool *)malloc(sizeof(thread_pool));
	if (pool == NULL)
	{
#ifdef PRT
		PST("Malloc error");
#endif
		return -1;
	}

	assert(pool != NULL);
	pthread_mutex_init(&(pool->mutex), NULL);		/* 锁 */
	pthread_cond_init(&(pool->cond), NULL);			/* 条件 */
	pool->nthreads = num;
	pool->totaltasks = pool->runtasks = 0;			/* 当前总接受的任务数和运行任务数 */
	pool->shut = 0;									/* 关闭标志 */
	pool->head = pool->tail = NULL;
	pool->head = pool->tail = malloc(sizeof(task));	/* 初始化头尾指针 */
	pthread_attr_init(&attr);						/* 属性 */
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	for (i = 0; i < num; i++)
	{
		/* 创建线程 */
		if ((err = pthread_create(&pid, &attr, thread_func, NULL)) != 0)	
		{
			return err;
		}
	}
	pthread_attr_destroy(&attr);
	return 0;
}

/*
 * 给线程池中加入任务
 */
void
insert_task_to_pool(void *data)
{
	task *mytask;
	mytask = (task *)malloc(sizeof(task));		/* 在堆上分配 */
	if (mytask == NULL)
	{
#ifdef PRT
		PST("Malloc task error");
#endif
		return ;
	}

	mytask->data = data;
	pthread_mutex_lock(&(pool->mutex));
	pool->tail->next = mytask;
	mytask->prev = pool->tail;
	pool->tail = mytask;
	pool->tail->next = NULL;
	pool->totaltasks ++;						/* 任务数+1 */
	pool->waittasks ++;							/* 等待处理的任务数+1 */
#ifdef PRT
	printf("Add a task, the total tasks is %d, waittask is %d\n", pool->totaltasks, pool->waittasks);
#endif
	pthread_cond_signal(&(pool->cond));			/* 唤醒等待任务的线程 */
	pthread_mutex_unlock(&(pool->mutex));
	return ;
}

/*
 * 删除线程池中尾任务
 */
void 
del_task_to_pool()
{
//	pthread_mutex_lock(&(pool->mutex));
	free(pool->tail->data);
	pool->tail->data = NULL;
	pool->tail = pool->tail->prev;
	free(pool->tail->next);
	pool->tail->next = NULL;
	pool->totaltasks --;
#ifdef PRT
	printf("Delete a task, the total tasks is %d, waittask is %d\n", pool->totaltasks, pool->waittask);
#endif
//  pthread_mutex_unlock(&(pool->mutex));
}	

/*
 * 线程函数
 */
void
*thread_func(void *arg)				/* 等待任务，无则阻塞 */
{
	int connfd;
	for (;;)
	{
		pthread_mutex_lock(&(pool->mutex));
		while (pool->waittasks == 0)
		  pthread_cond_wait(&(pool->cond), &(pool->mutex));
		connfd = *((int *)(pool->tail->data));
		pool->runtasks ++;			/* 处理过的任务数 */
		pool->waittasks --;			/* 等待处理的任务数 */
		del_task_to_pool();			/* 释放这个任务 */
		pthread_mutex_unlock(&(pool->mutex));	
									/* 解锁，使其他线程可以等待其他任务 */
		serve_machine(&connfd);		/* 任务开始执行 */
	}
}

/*
 * 释放线程池资源
 */
void
clear_pool(int signo)				/* 清除线程池 */
{
	task *temp;
#ifdef PRT
	printf("\n服务器正在关闭...\n");
#endif
	pthread_mutex_lock(&(pool->mutex));
	temp = pool->head->next;
	for (; temp != NULL; temp = pool->head->next)
	{
		free(pool->head->data);
		pool->head->data = NULL;
		if (pool->head->prev != NULL)
		{
			free(pool->head->prev);
			pool->head->prev = NULL;
		}
		free(pool->head);
		pool->head = NULL;
		pool->head = temp;
	}
	
	pthread_mutex_unlock(&(pool->mutex));
	pthread_mutex_destroy(&(pool->mutex));
	pthread_cond_destroy(&(pool->cond));
	free(pool);
	pool = NULL;
	free(temp);
	exit(0);
}
