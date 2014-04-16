#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "unbourne.h"

#include "handle_signal.h"

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
