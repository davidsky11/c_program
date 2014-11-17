/*
 * =====================================================================================
 *
 *       Filename:  msgtool.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/17/2014 03:59:17 PM
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
#include <ctype.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "../lib/tlpi_hdr.h"

#define MAX_MTEXT	80

struct mbuf
{
	long mtype;					/* Message type */
	char mtext[MAX_MTEXT];		/* Message body */
};

void send_message(int qid, struct mbuf *msg, long type, char *text);
void read_message(int qid, struct mbuf *msg, long type);
void remove_queue(int qid);
void change_queue_mode(int qid, char *mode);
void usage(void);

int main(int argc, char *argv[])
{
	key_t key;
	int qid;
	struct mbuf msg;

	if (argc == 1)
	  usage();

	/* Create unique key via call to ftok() */
	key = ftok(".", 'm');

	/* Open the queue - create if necessary */
	if ((qid = msgget(key, IPC_CREAT | 0660)) == -1)
		errExit("msgget");

	switch (tolower(argv[1][0]))
	{
		case 's':
			send_message(qid, (struct mbuf *) &msg, atol(argv[2]), argv[3]);
			break;

		case 'r':
			read_message(qid, &msg, atol(argv[2]));
			break;

		case 'd':
			remove_queue(qid);
			break;

		case 'm':
			change_queue_mode(qid, argv[2]);
			break;

		default:
			usage();
			break;
	}

	exit(EXIT_SUCCESS);
}

void read_message(int qid, struct mbuf *msg, long type)
{
	printf("Reading from queue...\n");
	msg->mtype = type;
	if (msgrcv(qid, (struct mbuf *) msg, MAX_MTEXT, type, 0) == -1)
		errExit("msgrcv");

	printf("Type: %ld Text: %s\n", msg->mtype, msg->mtext);
}

void send_message(int qid, struct mbuf *msg, long type, char *text)
{
	printf("Sending to queue...\n");
	msg->mtype = type;
	strcpy(msg->mtext, text);

	/* Send message */
	if (msgsnd(qid, (struct mbuf *) msg, strlen(msg->mtext)+1, 0) == -1)
		errExit("msgsnd");
}

void remove_queue(int qid)
{
	if (msgctl(qid, IPC_RMID, NULL) == -1)
		errExit("msgctl");
}

void change_queue_mode(int qid, char *mode)
{
	struct msqid_ds qds;

	/* Get current info */
	msgctl(qid, IPC_STAT, &qds);

	/* Convert and load the mode */
	sscanf(mode, "%ho", &qds.msg_perm.mode);

	/* Update the mode */
	msgctl(qid, IPC_SET, &qds);
}

void usage(void)
{
	fprintf(stderr, "msgtool - A utility for tinkering with msg queues\n");
	fprintf(stderr, "\nusage: msgtool	(s)end <type> <message text>\n");
	fprintf(stderr, "		(r)ecv <type>\n");
	fprintf(stderr, "		(d)elete\n");
	fprintf(stderr, "		(m)ode <octal mode>\n");
	exit(EXIT_SUCCESS);
}
