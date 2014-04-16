/**
 * @author Dylan Scott dsco9564
 */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include "unbourne.h"

#include "init.h"

void set_readme_path(void)
{
	char *character = readme_path;
	char *delimiter = NULL;

	/* find the last dir separator */
	while(*character != '\0')
	{
		if(*character == *DIR_SEPARATOR)
		{
			delimiter = character;
		}
		character++;
	}
	/* set the last dir separator to string end */
	*delimiter = '\0';
	strcat(readme_path, "/readme");
}


/* bugs
 * if called from path SHELL variable can be set incorrectly
 */

/* init - intitalise the shell
 * args - none
 * returns - none
 */
void init(char **argv)
{
    /* path to shell */
    char *shell = NULL;

    /* make sure we have an argument */
    if(argv[0] == NULL)
    {
        abort();
    }

    /* try to find real path to shell */
    shell = realpath(argv[0], shell);

    /* abort if shell not found */
    if(shell == NULL)
    {
		perror("realpath");
        abort();
    }

    /* set SHELL environment variable and check for errors */
    if(setenv(SHELL_VAR, shell, true) != 0)
    {
        /* show error */
        perror("setenv");
        abort();
    }

	strcpy(readme_path, shell);
	free(shell);
	set_readme_path();

}
