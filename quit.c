/**
 * @author Dylan Scott dsco9564
 */

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
