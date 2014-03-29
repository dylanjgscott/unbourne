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

	/* the directory to change to */
	char *path = args[1];

	/* the canonical name for the directory to change to */
	char *real = realpath(path, NULL);

	/* try to get the real directory */
	if(real != NULL)
	{
		/* change directory and check if successful */
		if(chdir(real) == 0)
		{
            /* try to set environment */
            if(setenv(PWD_VAR, real, true) != 0)
            {
                /* show error */
				perror("setenv");
				/* abort */
				abort();
            }
        }
        else
        {
			/* show error */
			perror("chdir");
        }
    }
    else
    {
		/* show error */
		perror("realpath");
    }
}
