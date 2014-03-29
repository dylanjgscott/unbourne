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
	char *shell = NULL;

	/* try realpath */
	shell = realpath(argv[0], shell);

    /* if we found the shell */
    if(shell != NULL)
	{
        /* set SHELL environment variable and check error */
        if(setenv(SHELL_VAR, shell, true) != 0)
        {
            /* show error */
            perror("setenv");
            /* abort */
            abort();
        }
    }

    /* if that didn't work shell was called from path */
    else
    {
        /* copy of path variable from environment */
        char *path_var = malloc(sizeof(char) * BUF_SIZE);

        /* list of path directories */
        char **paths = malloc(sizeof(char *) * ARGS_SIZE);

        /* create a possible shell location */
        char *possible_shell_path = malloc(sizeof(char) * BUF_SIZE);

		/* pointer to current path */
        char **path = paths;

		/* check that malloc has allocated memory */
		if(!path_var)
		{
			/* show error */
			perror("malloc");
			/* abort */
			abort();
		}

		/* check that malloc has allocated memory */
		if(!paths)
		{
			/* show error */
			perror("malloc");
			/* abort */
			abort();
		}

		/* check that malloc has allocated memory */
		if(!possible_shell_path)
		{
			/* show error */
			perror("malloc");
			/* abort */
			abort();
		}

		/* make copy of path variable */
        path_var = strcpy(path_var, getenv(PATH_VAR));

        /* start tokenising the path */
        *path = strtok(path_var, PATH_SEPARATOR);

        /* finish tokenising the path */
        while((*path++ = strtok(NULL, PATH_SEPARATOR)));

        /* move back to the first path */
        path = paths;

        /* loop through all the paths */
        while(*path)
        {
            /* add the path */
            strcpy(possible_shell_path, *path);

            /* add a directory separator */
            strcat(possible_shell_path, DIR_SEPARATOR);

            /* add the name of the executable */
            strcat(possible_shell_path, argv[0]);

            /* see if it exists */
            shell = realpath(possible_shell_path, shell);

            /* if we fould our shell path */
            if(shell != NULL)
            {
                /* set SHELL environment variable and check error */
                if(setenv(SHELL_VAR, shell, true) != 0)
                {
                    /* show error */
                    perror("setenv");
                    /* abort */
                    abort();
                }
                break;
            }
            /* move to the next path */
            path++;
        }
        /* free unused memory */
        free(possible_shell_path);
        free(path_var);
        free(paths);
    }
}
