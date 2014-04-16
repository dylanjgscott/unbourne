/**
 * @author Dylan Scott dsco9564
 */

#include <stdlib.h>

#include "quit.h"

/* quit
 * exit the shell
 *
 * arguments:
 *  args - unused
 *
 * returns:
 *  nothing
 */
void quit(char **args)
{
	/*unused parameter*/
	(void)(args);

	/* quit */
	exit(EXIT_SUCCESS);
}
