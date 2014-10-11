/*
 * =====================================================================================
 *
 *       Filename:  test_become_daemon.c
 *
 *    Description:  ./test_become_daemon 1800
 *					ps -C test_become_daemon -o "pid ppid pgid sid tty command"
 *
 *        Version:  1.0
 *        Created:  10/07/2014 01:30:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "become_daemon.h"
#include "../lib/tlpi_hdr.h"

int main(int argc, char *argv[]) {
	becomeDaemon(0);

	sleep((argc > 1) ? getInt(argv[1], GN_GT_O, "sleep-time") : 20);

	exit(EXIT_SUCCESS);
}
