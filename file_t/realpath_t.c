#include <stdlib.h>

#define PATH_MAX 1024
#define _PC_PATH_MAX 5

char *realpath(const char *name, char *resolved)
{
	char *rpath = NULL;
	int path_max;
	if (name == NULL)
	{
		printf("Please input a right path or file name!\n");
		return NULL;
	}

	if (name[0] == '\0') 
	{
		printf("Please input a right path or file name!\n");
		return NULL;
	}

#define PATH_MAX
	path_max = PATH_MAX;
#else
	path_max = pathconf(name, _PC_PATH_MAX);
	if (path_max <= 0)
		path_max = 4096;
#endif

	if (resolved == NULL)
	{
		rpath = malloc(path_max);
		if (rpath = NULL)
			return NULL;
	}
	else
		rpath = resolved;

	
}
