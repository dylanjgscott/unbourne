#include <stdio.h>
#include <stdlib.h>

#include "unbourne.h"

#include "handle.h"
#include "parse.h"

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

	/* read until the end of file */
	while(!feof(file))
	{
        /* display a prompt if appropriate */
        if(prompt)
        {
            printf("%s:%s$ ", SHELL_NAME, getenv(CWD_VAR));
        }

		/* if there is a command to process */
		if(fgets(buf, BUF_SIZE, file))
		{

			/* process the command */
			parse(buf);

		}

	}

    /* print a new line at program termination */
    printf("\n");

}
