#include <stdlib.h>

#include "clear.h"

/* clear - clears the screen by calling system clear
 * args - none
 */
void clear(char **args)
{
	(void)(args); /*unused parameter*/
	system("clear");
}
