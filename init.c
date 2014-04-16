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

/* set_readme_path
 *
 * sets the path to the readme file by using the path to the shell.
 *
 * arguments:
 *  shell_path - the path to the shell
 *
 * returns:
 *  nothing
 */
void set_readme_path(char *shell_path)
{
	char *character = readme_path;
	char *delimiter = NULL;

	strcpy(readme_path, shell_path);

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
	strcat(readme_path, DIR_SEPARATOR);
	strcat(readme_path, README_FILENAME);
}


/* init
 *
 * intitalise the shell
 *
 * arguments:
 *  args - the arguments passed in to the main function
 *
 * returns:
 *  nothing
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

	set_readme_path(shell);
	free(shell);

}
