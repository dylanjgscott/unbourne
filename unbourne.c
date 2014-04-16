/**
 * @author Dylan Scott dsco9564
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>

#include "unbourne.h"

#include "init.h"
#include "handle.h"
#include "handle_signal.h"

/* main
 *
 * program entry point
 */
int main(int argc, char** argv)
{
    /* initalise our shell */
    init(argv);

	signal(SIGINT, handle_signal);

	/* If no argument given, read stdin and display prompt */
	if(argc == 1)
	{
		handle(stdin, true);
	}

	/* If arguments are not given, process those files without prompt */
	else
	{
		/* for each argument */
		int i;
		for(i = 1; i < argc; i++)
		{
			/* open the file */
			FILE* file = fopen(argv[i], "r");
			if(file)
			{
				/* process the commands */
				handle(file, false);
			}
			/* close the file */
			fclose(file);
		}
	}
	return EXIT_SUCCESS;
}
