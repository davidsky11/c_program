/*
 * =====================================================================================
 *
 *       Filename:  shmtool.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/17/2014 05:10:30 PM
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
#include <sys/ipc.h>
#include <sys/shm.h>

#define SEGSIZE 100

void writeshm (int shmid, char *segptr, char *text);
void readshm (int shmid, char *segptr);
void removeshm (int shmid);
void changemode (int shmid, char *mode);
void usage ();

int
main (int argc, char *argv[])
{
    key_t key;
    int shmid, cntr;
    char *segptr;

    if (argc == 1)
	usage ();

    /* Create unique key via call to ftok() */
    key = ftok (".", 'S');

    /* Open the shared memory segment - create if necessary */
    if ((shmid = shmget (key, SEGSIZE, IPC_CREAT | IPC_EXCL | 0666)) == -1)
	{
		printf ("Shared memory segment exists - opening as client\n");

		/* Segment probably already exists - try as a client */
		if ((shmid = shmget (key, SEGSIZE, 0)) == -1)
	    {
			perror ("shmget");
			exit (1);
	    }
	}
	else
	{
		printf ("Creating new shared memory segment\n");
	}

    /* Attach (map) the shared memory segment into the current process */
    if ((segptr = shmat (shmid, NULL, 0)) == (void *) -1)
	{
		perror ("shmat");
		exit (1);
	}

    switch (tolower (argv[1][0]))
	{
		case 'w':
			writeshm (shmid, segptr, argv[2]);
			break;

		case 'r':
			readshm (shmid, segptr);
			break;

		case 'd':
			removeshm (shmid);
			break;

		case 'm':
			changemode (shmid, argv[2]);
			break;

		default:
			usage ();
      }
}

void
writeshm (int shmid, char *segptr, char *text)
{
    strcpy (segptr, text);
    printf ("Done...\n");
}

void
readshm (int shmid, char *segptr)
{
    printf ("segptr: %s\n", segptr);
}

void
removeshm (int shmid)
{
    shmctl (shmid, IPC_RMID, 0);
    printf ("Shared memory segment marked for deletion\n");
}

void
changemode (int shmid, char *mode)
{
    struct shmid_ds myshmds;

    /* Get current values for internal data structure */
    shmctl (shmid, IPC_STAT, &myshmds);

    /* Display old permissions */
    printf ("Old permissions were: %o\n", myshmds.shm_perm.mode);

    /* Convert and load the mode */
    sscanf (mode, "%ho", &myshmds.shm_perm.mode);

    /* Update the mode */
    shmctl (shmid, IPC_SET, &myshmds);

    printf ("New permissions are : %o\n", myshmds.shm_perm.mode);
}

void
usage ()
{
	fprintf (stderr,
	     "shmtool - A utility for tinkering with shared memory\n");
    fprintf (stderr, "\nUSAGE: shmtool (w)rite <text>\n");
    fprintf (stderr, "               (r)ead\n");
    fprintf (stderr, "               (d)elete\n");
    fprintf (stderr, "               (m)ode change <octal mode>\n");
    exit (1);
}
