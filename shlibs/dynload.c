/*
 * =====================================================================================
 *
 *       Filename:  dynload.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/24/2014 11:15:26 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <dlfcn.h>
#include "../lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
	void *libHandle;		/* Handle for shared library */
	void (*func_init) (void);	/* Pointer to function with no arguments */
	void (*func_showMsg) (char *msg);
	
	const char *err;

	if (argc < 3 || strcmp(argv[1], "--help") == 0)
		usageErr("%s lib=path func=name\n", argv[0]);

	/* Load the shared library and get a handle for later use */
	libHandle = dlopen(argv[1], RTLD_LAZY);
	if (NULL == libHandle)
		fatal("dlopen: %s", dlerror());

	/* Search library for symbol named in argv[2] */
	(void) dlerror();		/* Clear dlerror() */
	if (argc == 3)
		*(void **) (&func_init) = dlsym(libHandle, argv[2]);

	if (argc == 4)
		*(void **) (&func_showMsg) = dlsym(libHandle, argv[2]);
	
	err = dlerror();
	if (err != NULL)
		fatal("dlsym: %s", err);

	/* If the address returned by dlsym() is non-NULL, try calling it 
	 * as a function that takes no arguments */
	if (func_init == NULL && func_showMsg == NULL)
		printf("%s is NULL\n", argv[2]);
	else
	{
		if (argc == 3)
			(*func_init)();
		if (argc == 4)
			(*func_showMsg)(argv[3]);
	}

	dlclose(libHandle);		/* Close the library */

	exit(EXIT_SUCCESS);
}
