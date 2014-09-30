/**
 * 
 */

#include <signal.h>
#include "../lib/tlpi_hdr.h"

static void sigHandler(int sig)
{
	static int count = 0;

	if (sig == SIGINT)
	{
		count ++;
		printf("Caught SIGINT (%d)\n", count);
		return;			/* Resume execution at point of interruption */
	}
	
	printf("Caught SIGQUIT - that's all folks!\n");
	exit(1);
}

int main(int argc, char *argv[])
{
	int j;
	
	if (signal(SIGINT, sigHandler) == SIG_ERR)
		printf("signal failed!\n");

	if (signal(SIGQUIT, sigHandler) == SIG_ERR)
		printf("signal failed!\n");

	/*for (j = 0; j < 10; j++)
	{
		printf("%d\n", j);
		sleep(1);
	}*/

	for (;;)			/* Loop forever, waiting for signals */
		pause();		/* Block until a signal is caught */
}
