#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include "unbourne.h"

#include "init.h"

/* bugs
 * if called from path SHELL variable can be set incorrectly
 */

/* init - intitalise the shell
 * args - none
 * returns - none
 */
void init(char **argv)
{
	/* shell path */
	char *shell = malloc(sizeof(char) * BUF_SIZE);

	/* check that malloc has allocated memory */
	if(!shell)
	{
		/* show error */
		perror("malloc");
		/* abort */
		abort();
	}

	/* try realpath */
	shell = realpath(argv[0], shell);

    /* called from relative path */
    if(shell != NULL)
    {
        /* set SHELL environment variable and check success */
        if(setenv(SHELL_VAR, shell, true) != 0)
		{
			/* show error */
			perror("setenv");
			/* abort */
			abort();
		}
    }

    /* called from path */
    else
    {
        /* pointer to current path variable */
        char *path_var = malloc(sizeof(char) * BUF_SIZE);

        /* list of path directories */
        char **paths = malloc(sizeof(char *) * ARGS_SIZE);

		/* pointer to current path */
        char **path = paths;

		/* check that malloc has allocated memory */
		if(!shell)
		{
			/* show error */
			perror("malloc");
			/* abort */
			abort();
		}

		/* check that malloc has allocated memory */
		if(!shell)
		{
			/* show error */
			perror("malloc");
			/* abort */
			abort();
		}

		/* make copy of path variable */
        path_var = strcpy(path_var, getenv(PATH_VAR));

        /* begin tokenising the path variable */
        *path = strtok(path_var, PATH_SEPARATORS);

        /* finish tokenising the path variable */
        while((*path++ = strtok(NULL, PATH_SEPARATORS)));

        /* go back to the first path in the list */
        path = paths;

        /* move though each dir in the path list */
        while(*path)
        {

			/* use working dir instead */
			strcpy(shell, *path);

            /* append directory separator */
            strcat(shell, DIR_SEPARATOR);

            /* append process name */
            strcat(shell, argv[0]);

			/* get real path */
			shell = realpath(shell, shell);

			/* check if real path exists */
			if(shell != NULL)
			{

				/* if our possible shell is execuable */
				if(access(shell, X_OK) != -1)
				{
					/* set the shell environment var to our shell */
					if(setenv(SHELL_VAR, shell, true) != 0)
					{
						/* show error */
						perror("setenv");
						/* abort */
						abort();
					}
					break;
				}
			}
			/* move to next path */
			paths++;
        }
		/* free unused memory */
        free(path_var);
        free(paths);
    }
}
