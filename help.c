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

#include "help.h"

#include "parse.h"

/* help
 *
 * show readme
 *
 * arguments:
 *  args - unused
 *
 * returns:
 *  nothing
 */
void help(char **args)
{
	/* arguments for command */
	char *command_args[ARGS_SIZE];
	char **command_arg = command_args;

	/* unused parameter */
	(void)(args);

	/* set command as first argument */
	*command_arg++ = MORE_CMD;

	/* set options as second argument */
	*command_arg++ = readme_path;

	/* switch processes and check for errors */
	if(execvp(command_args[0], command_args) == -1)
	{
		/* show error */
		perror("exec");
		abort();
	}

}
