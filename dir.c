/**
 * @author Dylan Scott dsco9564
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "unbourne.h"

#include "dir.h"

#include "parse.h"

/* dir
 *
 * list directory contents
 *
 * arguments:
 *  args - list of directories to display
 *
 * returns:
 *  nothing
 */
void dir(char **args)
{
	/* arguments for command */
	char *command_args[ARGS_SIZE];

	/* pointer to current argument */
	char **arg = args;
	char **command_arg = command_args;

	/* set command as first argument */
	*command_arg++ = DIR_CMD;

	/* set options as second argument */
	*command_arg++ = DIR_OPTS;

	/* skip the first argument */
	arg++;

	/* put the directories */
	while(*arg != NULL)
	{
		*command_arg++ = *arg++;
	}
	*command_arg++ = NULL;

	/* switch processes and check for errors */
	if(execvp(command_args[0], command_args) == -1)
	{
		/* show error */
		perror("exec");
		abort();
	}

}
