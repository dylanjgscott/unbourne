/**
 * @author Dylan Scott dsco9564
 */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>

#include "unbourne.h"

#include "parse.h"

#include "builtins.h"
#include "redirect.h"

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
	/* wait for child process */
	bool wait = true;

	/* input file for child program */
	char *in_file = NULL;

	/* output file for child program */
	char *out_file = NULL;

	/* append mode false by default */
	bool append = false;

	/* list of arguments */
	char *args[ARGS_SIZE];

	/* pointer to current argument */
	char **arg = args;

	/* start tokenising the arguments */
	*arg++ = strtok(line, DELIMITERS);

	/* tokenise the remaining argumetns */
	while((*arg++ = strtok(NULL, DELIMITERS)));

	arg = args;

	/* check arguments for redirection and background commands */
	while(*arg)
	{
		/* if input redirect requested */
		if(strcmp(*arg, IN_REDIRECT_CMD) == 0)
		{
			/* set this argument to null and move to the next */
			*arg++ = NULL;

			/* set input file */
			in_file = *arg;
		}
		/* if output redirect requested */
		else if(strcmp(*arg, OUT_REDIRECT_CMD) == 0)
		{
			/* set this argument to null and move to the next */
			*arg++ = NULL;

			/* set output file */
			out_file = *arg;
		}
		/* if output redirect requested */
		else if(strcmp(*arg, APPEND_REDIRECT_CMD) == 0)
		{
			/* set this argument to null and move to the next */
			*arg++ = NULL;

			/* set output file */
			out_file = *arg;

			/* set append mode */
			append = true;
		}
		/* if background requested */
		else if(strcmp(*arg, BACKGROUND_CMD) == 0)
		{
			/* set this argument to null and move to the next */
			*arg++ = NULL;
			/* do not wait for child process */
			wait = false;
		}
		arg++;
	}

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
				break;
			}
			/* move to the next built in command */
			builtin++;
		}
		/* if we could not find an internal command or the command is a fork command */
		if(builtin->func == NULL || builtin->fork == true)
		{
			/* create another process */
			switch(child_pid = fork())
			{
				/* fork error */
				case -1:
					/* show error */
					perror("fork");

				/* this process is the child process */
				case 0:
					/* do any redirects */
					redirect(in_file, out_file, append);

					/* set parent variable */
					setenv("PARENT", getenv(SHELL_VAR), 1);

					/* if this is not a built-in command */
					if(builtin->func == NULL)
					{
						/* switch process */
						if(execvp(args[0], args) == -1)
						{
							perror("exec");
							abort();
						}
					}
					/* if this is a built-in command */
					else
					{
						/* run the built-in function */
						builtin->func(args);
						exit(EXIT_SUCCESS);
					}

				/* this process is the parent process */
				default:
					/* if wait is requested */
					if(wait)
					{
						/* wait for child process */
						waitpid(child_pid, NULL, 0);
					}
					child_pid = 0;
			}
		}
		else
		{ 
			/* run the built-in command */
			builtin->func(args);
		}
	}
}
