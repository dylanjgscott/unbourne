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
	/* pointer to current env variable */
	char **var = environ;

	/*unused parameter*/
	(void)(args);

	/* loop through all env vars */
	while(*var != NULL)
	{
		/* print var */
		printf("%s\n", *var);
		/* move to next var */
		var++;
	}
}
