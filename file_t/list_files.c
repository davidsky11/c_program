#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef enum{TRUE, FALSE}	Boolean;
int errno;

static void listFiles(const char *dirpath)
{
	DIR *dirp;
	struct dirent *dp;
	Boolean isCurrent;

	isCurrent = strcmp(dirpath, ".") == 0;

	dirp = opendir(dirpath);
	if (dirp == NULL) 
	{
		printf("opendir failed!\n");
		return;
	}

	for(;;)
	{
		errno = 0;
		dp = readdir(dirp);
		if (dp == NULL)
			break;

		if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
			continue;

		if (!isCurrent)
			printf("%s/", dirpath);
		printf("%s\n", dp->d_name);
	}

	if (errno != 0)
		printf("readdir failed!\n");

	if (closedir(dirp) == -1)
		printf("closedir failed!\n");
}

int main(int argc, char *argv[])
{
	if (argc >1 && strcmp(argv[1], "--help") == 0)
		printf("%s [dir...]\n", argv[0]);

	if (argc == 1)
		listFiles(".");
	else 
		for (argv++; *argv; argv++)
			listFiles(*argv);

	exit(1);
}

