#ifndef builtins_h
#define builtins_h 1

#include "clear.h"
#include "dir.h"
#include "env.h"
#include "quit.h"

struct builtin
{
	char *cmd;
	void (*func) (char **args);
};

struct builtin builtins[] = {
	{ "clr", clear},
	{ "dir", dir},
	{ "environ", env},
	{ "quit", quit},
};

#endif
