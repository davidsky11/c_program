#include <pwd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uname.h>
#include <stdlib.h>

typedef enum{ TRUE, FALSE } Boolean;

uid_t userIdfromName(const char *name)
{
	struct passwd *pwd;
	uid_t u;
	char *endptr;
	if (name == NULL || *name =='\0')
		return -1;
	u = strtol(name, &endptr, 10);
	if (*endptr == '\0')
		return u;

	pwd = getpwnam(name);
	if (pwd == NULL)
		return -1;

	return pwd->pw_uid;
}

void listPid()
{
	DIR *dirp;
	struct dirent *dp;
	Boolean isCurrent;
}
