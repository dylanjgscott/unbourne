/**
 * @author Dylan Scott dsco9564
 */

#include <stdlib.h>

#include "clear.h"

/* clear - clears the screen by calling system clear
 * args - none
 */
void clear(char **args)
{
	/*unused parameter*/
	(void)(args);

	/* clear the screen */
	system("clear");
}
