#include <stdlib.h>
#include <stdio.h>

#include "env.h"

/* envionment variables */
extern char **environ;

/* env - print environment variables
 * args - not used
 */
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
