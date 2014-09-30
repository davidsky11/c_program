/*
 * =====================================================================================
 *
 *       Filename:  check_password.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/10/2014 02:40:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), shiya.gang@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#define _BSD_SOURCE
#define _XOPEN_SOURCE
#include <unistd.h>
#include <limits.h>
#include <pwd.h>
#include <shadow.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef enum {
	true, 
	false,
} Boolean;

int main(int argc, char *argv[]) {
	char *username, *password, *encrypted, *p;
	struct passwd *pwd;
	struct spwd *spwd;
	Boolean authOk;
	size_t len;
	long lnmax;
	lnmax = sysconf(_SC_LOGIN_NAME_MAX);
	if (lnmax == -1)
	  lnmax = 256;

	username = malloc(lnmax);
	if (username == NULL)
	  exit(EXIT_SUCCESS);

	printf("Username: ");
	fflush(stdout);
	if (fgets(username, lnmax, stdin) == NULL)
	  exit(EXIT_FAILURE);

	len = strlen(username);
	if (username[len -1] == '\n')
	  username[len - 1] = '\0';

	pwd = getpwnam(username);
	if (pwd == NULL)
	  printf("couldn't get password record!\n");

	spwd = getspnam(username);
	if (spwd == NULL && errno == EACCES)
		printf("no permission to read shadow password file\n");

	if (spwd != NULL)
	  pwd->pw_passwd = spwd->sp_pwdp;

	password = getpass("Password: ");

	/*  Encrypted password and erase cleartext version immediately */
	encrypted = crypt(password, pwd->pw_passwd);
	for (p = password; *p != '\0';)
	  *p++ = '\0';

	if (encrypted == NULL)
	  perror("crypt");

	authOk = strcmp(encrypted, pwd->pw_passwd) == 0;
	if (!authOk) {
	  printf("Incorrect password\n");
		exit(EXIT_FAILURE);
	}

	printf("Successfully authenticated: UID=%ld\n", (long) pwd->pw_uid);

	/* Now do authenticated work... */
	exit(EXIT_SUCCESS);
	
}
