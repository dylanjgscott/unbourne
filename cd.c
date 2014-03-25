#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "cd.h"

/* cd - change directory
 * args - the directory to change to
 * returns - nothing
 */
void cd(char **args)
{
	/* check for absolute path */
	if(args[1][0] == '/')
	{
		/* check if chdir was successful */
		if(chdir(args[1]) == 0)
		{
			/* try to set environment */
			if(setenv(PWD_VAR, args[1], true) != 0)
			{
				/* show error */
				fprintf(stderr, "Error: could not set working directory in environment.\n");
			}
		}
		else
		{
			/* show error */
			fprintf(stderr, "Error: could not change directory to '%s'.\n", args[1]);
		}
	}
	else
	{
		/* show error */
		fprintf(stderr, "Error: You must use an absolute path.\n");
	}
}
