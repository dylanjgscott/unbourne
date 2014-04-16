/**
 * @author Dylan Scott dsco9564
 */

#include <stdio.h>
#include <stdlib.h>

#include "redirect.h"

/* redirect
 *
 * reopens stdin and/or stdout
 *
 * arguments:
 *  in_file - the file to read stdin from
 *  out_file - the file to write stdout to
 *  append - if true, stdout will be set to append mode
 *
 * returns:
 *  nothing
 */
void redirect(char *in_file, char *out_file, bool append)
{
	/* check for stdin redirect */
	if(in_file != NULL)
	{
		/* reopen stdin */
		stdin = freopen(in_file, "r", stdin);
		/* check for error */
		if(stdin == NULL)
		{
			perror("freopen");
			abort();
		}
	}

	/* check for stdout redirect */
	if(out_file != NULL)
	{
		/* if append mode */
		if(append)
		{
			/* reopen stdout */
			stdout = freopen(out_file, "a", stdout);
		}
		/* if not append mode */
		else
		{
			/* reopen stdout */
			stdout = freopen(out_file, "w", stdout);
		}
		/* check for error */
		if(stdout == NULL)
		{
			perror("freopen");
			abort();
		}
	}
}
