#include "handle.h"

/* handle
 *
 * reads commands from file line by line and process them
 *
 * arguments:
 *  file - file to read commands from
 *  prompt - if set to true, will output prompt to stdout
 *
 * returns:
 *	nothing
 */

void handle(FILE* file, bool prompt)
{

	/* buffer to read into */
	char buf[BUF_SIZE];

	/* display a prompt if appropriate */
	if(prompt)
	{
		printf("%s", PROMPT);
	}

	/* read until the end of file */
	while(!feof(file))
	{

		/* if there is a command to process */
		if(fgets(buf, BUF_SIZE, file))
		{

			/* process the command */
			parse(buf);

			/* display a prompt if appropriate */
			if(prompt)
			{
				printf("%s", PROMPT);
			}

		}

	}

}
