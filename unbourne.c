#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "unbourne.h"

#include "handle.h"

/*
 * Unbourne Shell
 * Author: Dylan Scott
 * Copyright 2014
 *
 * Usage: unbourne [FILE...]
 *
 * Very basic shell. Most commands passed to sh anyway.
 *
 * Intenal commands:
 *	clr - clear the screen
 *	dir [DIRECTORY...] - show directory contents
 *	quit - exit the shell
 *	environ - show environment variables
 *
 */
int main(int argc, char** argv)
{
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
