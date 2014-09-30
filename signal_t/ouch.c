#include <signal.h>
#include "../lib/tlpi_hdr.h"

static void sigHandler(int sig)
{
	printf("\t Ouch! %d\n", sig);
}

int main(int argc, char *argv[])
{
	int j;
	
	if (signal(SIGINT, sigHandler) == SIG_ERR)
		printf("signal failed!\n");

	for (j = 0; j < 10; j++)
	{
		printf("%d\n", j);
		sleep(1);
	}
}
