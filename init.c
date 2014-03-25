#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include "unbourne.h"

#include "init.h"

/* TODO
 *
 * use realpath
 */

/* init - intitalise the shell
 * args - none
 * returns - none
 */
void init(char **argv)
{
    /* called from relative path */
    if(*argv[0] == '.')
    {
        char shell[BUF_SIZE];
        getcwd(shell, BUF_SIZE);

        /* remove the leading dot */
        strcat(shell, argv[0]+1);

        /* set SHELL environment variable */
        setenv(SHELL_VAR, shell, true);
    }

    /* called from absolute path */
    else if(*argv[0] == '/')
    {
        char shell[BUF_SIZE];
        getcwd(shell, BUF_SIZE);
        strcat(shell, "/");
        /* set SHELL environment variable */
        setenv(SHELL_VAR, shell, true);
    }

    /* called from path */
    else
    {
        /* string use to assemble possible shell locations */
        char *path = malloc(sizeof(char) * BUF_SIZE);

        /* path variable */
        char *path_var = malloc(sizeof(char) * BUF_SIZE);

        /* list of path directories */
        char *path_dirs[ARGS_SIZE];

        /* pointer to current path directory */
        char **path_dir = path_dirs;

		/* make copy of path variable */
        path_var = strcpy(path_var, getenv(PATH_VAR));

        /* begin tokenising the path variable */
        *path_dir = strtok(path_var, PATH_SEPARATORS);

        /* finish tokenising the path variable */
        while((*path_dir++ = strtok(NULL, PATH_SEPARATORS)));

        /* go back to the first path in the list */
        path_dir = path_dirs;

        /* move though each dir in the path list */
        while(*path_dir)
        {

            /* if the directory is the cwd */
            if(strcmp(*path_dir, ".") == 0)
            {
                /* use working dir instead */
                strcpy(path, getenv(CWD_VAR));
            }
            /* current directory is not cwd */
            else
            {
                /* use full path */
                strcpy(path, *path_dir);
            }
            /* append directory separator */
            strcat(path, DIR_SEPARATOR);

            /* append process name */
            strcat(path, argv[0]);

            /* if our possible shell is execuable */
            if(access(path, X_OK) != -1)
            {
                /* set the shell environment var to our shell */
                setenv(SHELL_VAR, path, true);
                break;
            }
            path_dir++;
        }
        free(path);
        free(path_var);
    }
}
