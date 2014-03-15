#include "dir.h"

void dir(char **args)
{
	char dir_cmd[BUF_SIZE];
	char **arg = args;
	strncpy(dir_cmd, "ls -al", BUF_SIZE);
	arg++;
	while(*arg)
	{
		strcat(dir_cmd, " ");
		strcat(dir_cmd, *arg++);
	}
	system(dir_cmd);
}
