/*
 * =====================================================================================
 *
 *       Filename:  knlib.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/22/2014 09:24:04 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "knlib.h"

SignalFunc
signal_k(int sigNo, SignalFunc fun)
{
	struct sigaction act, oact;
	act.sa_handler = fun;
	sigemptyset(&act.sa_mask);		// Additional set of signals to be blocked.
	act.sa_flags = 0;
	if (sigaction(sigNo, &act, &oact) < 0)
	  return SIG_ERR;
	return oact.sa_handler;
}

void
sig_chld(int sigNo)
{
	pid_t pid;
	int state;
	while ((pid = waitpid(-1, &state, WNOHANG)) > 0)
	  printf("process %d terminated \n", pid);
	return;
}
