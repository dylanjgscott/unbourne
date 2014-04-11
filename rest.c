#include <stdlib.h>
#include <stdio.h>

#include "rest.h"

/* rest - pause until enter is pressed by the user
 * args - none
 */
void rest(char **args)
{
	/*unused parameter*/
	(void)(args);

	/* pause until enter is pressed */
	getchar();
}
