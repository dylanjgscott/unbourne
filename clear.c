/**
 * @author Dylan Scott dsco9564
 */

#include <stdlib.h>

#include "unbourne.h"

#include "clear.h"

/* clear
 *
 * clears the screen by calling system clear
 *
 * arguments:
 *  args - unused
 *
 * returns:
 *  nothing
 */
void clear(char **args)
{
	/*unused parameter*/
	(void)(args);

	/* clear the screen */
	system(CLEAR_CMD);
}
