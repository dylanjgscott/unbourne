/**
 * @author Dylan Scott dsco9564
 */

#include <stdlib.h>
#include <stdio.h>

#include "echo.h"

/* echo - print out arguments on stdout
 * args - the strings to be echoed
 */
void echo(char **args)
{
	/* pointer to current argument */
	char **arg = args;

	/* skip the first argument */
	arg++;

	/* while there are more args */
	while(*arg)
	{
		/* print the argument */
		printf("%s", *arg);

		/* move to the next argument */
		arg++;

		/* if there is an argument to follow */
		if(*arg)
		{
			/* print space */
			printf(" ");
		}
		/* last argument */
		else
		{
			/* print new line */
			printf("\n");
		}
	}
}
