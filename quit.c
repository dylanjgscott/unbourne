#include <stdlib.h>

#include "quit.h"

/* quit - exit the shell
 * args - none
 */
void quit(char **args)
{
	(void)(args); /*unused parameter*/
	exit(EXIT_SUCCESS);
}
