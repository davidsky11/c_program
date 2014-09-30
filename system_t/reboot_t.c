/*
 * =====================================================================================
 *
 *       Filename:  reboot_t.c
 *
 *    Description:  Reboot your device.
 *
 *        Version:  1.0
 *        Created:  09/10/2014 08:25:02 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), shiya.gang@163.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <linux/reboot.h>
#include <stdio.h>
#include <error.h>

void main(void) {
	int n = reboot(LINUX_REBOOT_CMD_RESTART);

	if (n == -1)
	  printf("reboot failed!\n");
}
