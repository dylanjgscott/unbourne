#include <stdlib.h>
#include <stdio.h>

#include "env.h"

extern char **environ;

void env(char **args)
{
	char **var = environ;
	(void)(args); /*unused parameter*/
	while(*var != NULL)
	{
		printf("%s\n", *var);
		var++;
	}
}
