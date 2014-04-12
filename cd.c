/**
 * @author Dylan Scott dsco9564
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>

#include "unbourne.h"

#include "cd.h"

/* cd - change directory
 * args - the directory to change to
 * returns - nothing
 */
void cd(char **args)
{

	/* the real path of the directory */
	char *path = NULL;

	/* cd requires an argument */
	if(args[1] == NULL)
	{
		return;
	}

	/* get the real path */
	path = realpath(args[1], path);

	/* if real path failed */
	if(path == NULL)
	{
		/* show error */
		perror("realpath");
		return;
	}

	/* change directory and check for error */
	if(chdir(path) != 0)
	{
		/* show error */
		perror("chdir");
		return;
	}
	
	/* try to set environment and check for error */
	if(setenv(PWD_VAR, path, true) != 0)
	{
		/* show error */
		perror("setenv");
		abort();
	}

	free(path);
}
