/**
 * @author Dylan Scott dsco9564
 */

#ifndef builtins_h
#define builtins_h 1

#include <stdbool.h>

#include "cd.h"
#include "clear.h"
#include "dir.h"
#include "env.h"
#include "quit.h"
#include "rest.h"
#include "echo.h"
#include "help.h"

/* struct builtin - associates a bulit-in command with a function */
struct builtin
{
	/* the command entered by the user */
	char *cmd;
	/* the function to run */
	void (*func) (char **args);
	/* shows if the shell fork for this command */
	bool fork;
};

/* list of all builtin functions */
struct builtin builtins[] =
{
	{"cd", cd, false},
	{"echo", echo, true},
	{"clr", clear, false},
	{"dir", dir, true},
	{"environ", env, true},
	{"quit", quit, false},
	{"pause", rest, false},
	{"help", help, true},
	{NULL, NULL, false},
};

#endif
