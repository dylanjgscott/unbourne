#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

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
	char *args[ARGS_SIZE];

	/* pointer to current argument */
	char **arg = args;

	/* start tokenising the arguments */
	*arg++ = strtok(line, DELIMITERS);

	/* tokenise the remaining argumetns */
	while((*arg++ = strtok(NULL, DELIMITERS)));

	/* if there are some arguments */
	if(*args != NULL)
	{
		/* the command is the first argument */
		char *cmd = args[0];

		/* pointer to current built-in command */
		struct builtin *builtin = builtins;

		/* try to match the cmd with the internal commands */
		while(builtin->cmd != NULL && builtin->func != NULL)
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
		/* if we could not find an internal command */
		if(builtin->cmd == NULL || builtin->func == NULL)
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
					/* show error */
					perror("fork");

				/* this process is the child process */
				case 0:
					/* switch process */
					if(execvp(args[0], args) == -1)
                    {
                        perror("exec");
                        abort();
                    }

				/* this process is the parent process */
				default:
					/* wait for child process */
					waitpid(pid, &status, 0);
			}
		}
	}
}
