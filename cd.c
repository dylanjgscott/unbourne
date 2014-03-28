#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "unbourne.h"

#include "cd.h"

/* cd - change directory
 * args - the directory to change to
 * returns - nothing
 */
void cd(char **args)
{

    /* check if chdir was successful */
    if(chdir(args[1]) == 0)
    {
        /* get the real directory */
        char *real = realpath(args[1], NULL);
            /* check if we got a real path */
        if(real != NULL)
        {
            /* try to set environment */
            if(setenv(PWD_VAR, real, true) != 0)
            {
                /* show error */
                fprintf(stderr, "Error: could not set working directory in environment.\n");
            }
        }
        else
        {
            fprintf(stderr, "Error: real path was null.\n");
        }
    }
    else
    {
        /* show error */
        fprintf(stderr, "Error: could not change directory to '%s'.\n", args[1]);
    }
}
