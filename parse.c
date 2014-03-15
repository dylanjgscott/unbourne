#include "parse.h"

/* shell environment variables */
extern char** environ;

/* parse
 *
 * interpret a command line and take the appropriate action.
 */

void parse(char* line)
{
	char split[BUF_SIZE];
	char* args[ARGS_SIZE];
	char** arg = args;
	strncpy(split, line, BUF_SIZE);
	*arg++ = strtok(split, DELIMITERS);
	while((*arg++ = strtok(NULL, DELIMITERS)));
	arg = args;
	if(*arg)
	{
		char* cmd = *arg;
		if(strcmp(cmd, "clr") == 0)
		{
			system("clear");
		}
		else if(strcmp(cmd, "dir") == 0)
		{
			char dir_cmd[BUF_SIZE];
			strncpy(dir_cmd, "ls -al", BUF_SIZE);
			arg++;
			while(*arg)
			{
				strncat(dir_cmd, " ", BUF_SIZE);
				strncat(dir_cmd, *arg++, BUF_SIZE);
			}
			system(dir_cmd);
		}
		else if(strcmp(cmd, "environ") == 0)
		{
			char** var = environ;
			while(*var)
			{
				printf("%s\n", *var++);
			}
		}
		else if(strcmp(cmd, "quit") == 0)
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			system(line);
		}
	}
}
