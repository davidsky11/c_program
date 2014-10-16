/*
 * =====================================================================================
 *
 *       Filename:  semun.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/15/2014 01:58:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef SEMUN_H
#define SEMUN_H

#include <sys/types.h>
#include <sys/sem.h>

union semun {					/* Used in calls to semctl() */
	int					val;
	struct semid_ds *	buf;
	unsigned short *	array;
#if defined(__linux__)
	struct seminfo *	__buf;
#endif
};

#endif
