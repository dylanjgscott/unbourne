#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#include "unbourne.h"

#include "parse.h"

#include "builtins.h"

/* parse
 *
 * interpret a command line and take the appropriate action.
 *
 * arguments:
 *	line - the command line to interpret
 *
 * returns:
 *  nothing
 */

void parse(char *line)
{
	/* list of arguments */
	char **args = malloc(sizeof(char *) * ARGS_SIZE);

	/* pointer to current argument */
	char **arg = args;

	/* start tokenising the arguments */
	*arg++ = strtok(line, DELIMITERS);

	/* tokenise the remaining argumetns */
	while((*arg++ = strtok(NULL, DELIMITERS)));

	/* if there are some arguments */
	if(*args)
	{
		/* the command is the first argument */
		char *cmd = args[0];

		/* pointer to current built-in command */
		struct builtin *builtin = builtins;

		/* try to match the cmd with the internal commands */
		while(builtin != NULL)
		{
			/* if cmd matches a built-in command */
			if(strcmp(cmd, builtin->cmd) == 0)
			{
				/* run the built-in function */
				builtin->func(args);
				break;
			}
			/* move to the next built in command */
			builtin++;
		}
		/* if we could find an internal command */
		if(builtin->cmd == NULL)
		{
			/* pid of child process */
			pid_t pid;

			/* return status of child process */
			int status;

			/* create another process */
			switch(pid = fork())
			{
				/* fork error */
				case -1:
					perror("fork");

				/* child process */
				case 0:
					/* switch process */
					execvp(args[0], args);

				/* parent process */
				default:
					/* wait for child process */
					waitpid(pid, &status, 0);
			}
		}
	}
	/* free arguments */
	free(args);
}
