#include "parse.h"

/* parse
 *
 * interpret a command line and take the appropriate action.
 */

void (*funcs[]) (char **args) = {
	clear,
	dir,
	env,
	quit,
	quit,
};

char *cmds[] = {
	"clr",
	"dir",
	"environ",
	"exit",
	"quit",
};

void parse(char *line)
{
	char line_copy[BUF_SIZE];
	char *args[ARGS_SIZE];
	char **arg = args;
	strncpy(line_copy, line, BUF_SIZE);
	*arg++ = strtok(line_copy, DELIMITERS);
	while((*arg++ = strtok(NULL, DELIMITERS)));
	if(*args)
	{
		char* cmd = args[0];
		int i = 0;
		while(cmds[i] != NULL)
		{
			if(strcmp(cmd, cmds[i]) == 0)
			{
				funcs[i](args);
				break;
			}
			i++;
		}
		if(cmds[i] == NULL)
		{
			system(line);
		}
	}
}
