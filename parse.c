#include <stdlib.h>
#include <string.h>

#include "unbourne.h"

#include "parse.h"

#include "builtins.h"

/* parse
 *
 * interpret a command line and take the appropriate action.
 */

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
		while(builtins[i].cmd != NULL)
		{
			if(strcmp(cmd, builtins[i].cmd) == 0)
			{
				builtins[i].func(args);
				break;
			}
			i++;
		}
		if(builtins[i].cmd == NULL)
		{
			system(line);
		}
	}
}
