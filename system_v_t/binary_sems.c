/*
 * =====================================================================================
 *
 *       Filename:  binary_sems.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/15/2014 01:49:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <sys/types.h>
#include <sys/sem.h>
#include "semun.h"
#include "binary_sems.h"

Boolean bsUseSemUndo = FALSE;
Boolean bsRetryOnEintr = TRUE;

int				/* Initialize semaphore to 1 (i.e., "available") */
initSemAvailable(int semId, int semNum)
{
	union semun arg;

	arg.val = 1;
	return semctl(semId, semNum, SETVAL, arg);
}

int				/* Initialize semaphore to 0 (i.e., "in use") */
initSemInUse(int semId, int semNum)
{
	union semun arg;

	arg.val = 0;
	return semctl(semId, semNum, SETVAL, arg);
}

/* Reserve semaphore (blocking), return 0 on success, or -1 with 'errno'
 * set to EINTR if operation was interrupted by signal handler */

int				/* Reserve semaphore - decrement it by 1 */
reserveSem(int semId, int semNum)
{
	struct sembuf sops;

	sops.sem_num = semNum;
	sops.sem_op = -1;
	sops.sem_flg = bsUseSemUndo ? SEM_UNDO : 0;

	while (semop(semId, &sops, 1) == -1)
	  if (errno != EINTR || !bsRetryOnEintr)
		return -1;

	return 0;
}

int				/* Release semaphore - increment it by 1 */
releaseSem(int semId, int semNum)
{
	struct sembuf sops;

	sops.sem_num = semNum;
	sops.sem_op = 1;
	sops.sem_flg = bsUseSemUndo ? SEM_UNDO : 0;

	return semop(semId, &sops, 1);
}
