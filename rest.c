/**
 * @author Dylan Scott dsco9564
 */

#include <stdlib.h>
#include <stdio.h>

#include "rest.h"

/* rest
 *
 * pause until enter is pressed by the user
 *
 * arguments:
 *  args - unused
 *
 * returns:
 *  nothing
 */
void rest(char **args)
{
	/*unused parameter*/
	(void)(args);

	/* pause until enter is pressed */
	while(getchar() != '\n');
}
