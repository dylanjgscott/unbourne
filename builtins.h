#ifndef builtins_h
#define builtins_h 1

#include "clear.h"
#include "dir.h"
#include "env.h"
#include "quit.h"

/* struct builtin - associates a bulit-in command with a function */
struct builtin
{
	/* the command entered by the user */
	char *cmd;
	/* the function to run */
	void (*func) (char **args);
};

/* list of all builtin functions */
struct builtin builtins[] =
{
	{ "clr", clear},
	{ "dir", dir},
	{ "environ", env},
	{ "quit", quit},
};

#endif
