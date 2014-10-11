/*
 * =====================================================================================
 *
 *       Filename:  become_daemon.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/07/2014 11:37:10 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef BECOME_DAEMON_H
#define BECOME_DAEMON_H

#define BD_NO_CHDIR				01	/* Don't chdir("/") */
#define BD_NO_CLOSE_FILES		02	/* Don't close all open files */
#define BD_NO_REOPEN_STD_FDS	03	/* Don't reopen stdin, stdout, and stderr to /dev/null */

#define BD_NO_UMASK0			010	/* Don't do a umask(0) */

#define BD_MAX_CLOSE			8192	/* Maximum file descriptors to close if sysconf(_SC_OPEN_MAX) is indeterminate */

int becomeDaemon(int flags);

#endif
