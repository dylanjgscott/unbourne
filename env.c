/**
 * @author Dylan Scott dsco9564
 */

#include <stdlib.h>
#include <stdio.h>

#include "env.h"

/* envionment variables */
extern char **environ;

/* env
 *
 * print environment variables
 *
 * arguments:
 *  args - not used
 *
 * returns:
 *  nothing
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
