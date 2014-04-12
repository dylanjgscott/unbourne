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
	pid_t pid;
	int status;
	char **arg = args;
	args[0] = DIR_CMD;
	while(*arg != NULL)
	{
		arg++;
	}
	*arg = DIR_OPTS;
	*arg++ = NULL;

	switch(pid = fork())
	{
		/* fork error */
		case -1:
			/* show error */
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
