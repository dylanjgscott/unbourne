#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "unbourne.h"

#include "dir.h"

#include "parse.h"

/* dir - list directory contents
 * args - directories to list
 */
void dir(char **args)
{
	/* child proccess id */
	pid_t pid;

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

	switch(pid = fork())
	{
		/* fork error */
		case -1:
			/* show error */
			perror("fork");

		/* child process */
		case 0:
			/* switch process */
			if(execvp(command_args[0], command_args) == -1)
			{
				/* show error */
				perror("exec");
				abort();
			}

		/* parent process */
		default:
			/* wait for child process */
			waitpid(pid, NULL, 0);
	}
}
