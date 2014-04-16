/**
 * @author Dylan Scott dsco9564
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "unbourne.h"

#include "handle_signal.h"

/* handle_signal
 *
 * handles the SIGINT signal. If a child process is running
 * SIGINT is sent to child process. If no child proccess is
 * running the shell terminates.
 *
 * arguments:
 *	signal - the signal number
 *
 * returns:
 *	nothing
 */
void handle_signal(int signal)
{
	if(signal == SIGINT)
	{
		if(child_pid == 0)
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			if(kill(child_pid, signal) != 0)
			{
				perror("kill");
			}
		}
	}
}
