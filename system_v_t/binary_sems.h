/*
 * =====================================================================================
 *
 *       Filename:  binary_sems.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/15/2014 01:45:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef BINARY_SEMS_H
#define BINARY_SEMS_H

#include "../lib/tlpi_hdr.h"

/* Variables controlling operation of functions below */

extern Boolean bsUseSemUndo;		/* Use SEM_UNDO during semop()? */
extern Boolean bsRetryOnEintr;		/* Retry if semop() interrupted by 
									   signal handler? */
int initSemAvailable(int semId, int semNum);

int initSemInUse(int semId, int semNum);

int reserveSem(int semId, int semNum);

int releaseSem(int semId, int semNum);

#endif
