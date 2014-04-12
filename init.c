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
    /* make sure we have an argument */
    if(argv[0] != NULL)
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

        /* free memory */
        free(shell);
    }

    /* no arguments */
    else
    {
        /* something went wrong */
        abort();
    }
}
