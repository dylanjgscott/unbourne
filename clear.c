#include <stdlib.h>

#include "clear.h"

void clear(char **args)
{
	(void)(args); /*unused parameter*/
	system("clear");
}
