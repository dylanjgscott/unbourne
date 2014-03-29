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
	char line_copy[BUF_SIZE]; /* copy of line */
	char *args[ARGS_SIZE]; /* list of arguments */
	char **arg = args; /* pointer to current argument */

	/* copy line to line_copy */
	strncpy(line_copy, line, BUF_SIZE);

	/* start tokenising the arguments */
	*arg++ = strtok(line_copy, DELIMITERS);

	/* tokenise the remaining argumetns */
	while((*arg++ = strtok(NULL, DELIMITERS)));

	/* if there are some arguments */
	if(*args)
	{
		/* the command is the first argument */
		char* cmd = args[0];

		/* try to match the cmd with the internal commands */
		int i = 0;
		while(builtins[i].cmd != NULL)
		{
			/* if cmd matches a built-in command */
			if(strcmp(cmd, builtins[i].cmd) == 0)
			{
				/* run the built-in function */
				builtins[i].func(args);
				break;
			}
			i++;
		}
		/* if we could find an internal command */
		if(builtins[i].cmd == NULL)
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
					fprintf(stderr, "Error: %d couldn't fork.\n", errno);

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
}
