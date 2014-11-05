/*
 * =====================================================================================
 *
 *       Filename:  thread_poll_t.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/01/2014 05:14:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _THREAD_POLL_T_H
#define _THREAD_POLL_T_H

#include <pthread.h>
#include <stdlib.h>
#include <assert.h>

#include "config.h"

typedef struct kvtask
{
	void				*data;		/* 套接子处理函数指针 */
	struct kvtask		*next;		/* 向后索引 */
	struct kvtask		*prev;		/* 向前索引 */
} task;

typedef struct pool
{
	pthread_mutex_t		mutex;		/* 锁和条件 */
	pthread_cond_t		cond;
	int					nthreads;	/* 线程池中的线程数 */
	int					totaltasks;	/* 线程池中的总任务数 */
	int					runtasks;	/* 正在服务的任务数 */
	int					shut;		/* 线程池关闭状态 */
	int					waittasks;	/* 等待空闲线程的任务数 */
	task				*head;		/* 任务头指针 */
	task				*tail;		/* 任务尾指针 */
} thread_pool;

void *thread_func(void *arg);		/* 线程函数 */
int initial_thread_pool(int num);	/* 线程池初始化 */
void insert_task_to_pool(void *data);	/* 增加任务 */
void del_task_to_pool();			/* 删除任务 */
void clear_pool(int signo);			/* 线程池资源释放 */

#endif
