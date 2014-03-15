#ifndef shell_h
#define shell_h 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "handle.h"

#define BUF_SIZE 1024
#define ARGS_SIZE 1024
#define PROMPT "unbourne $ "
#define DELIMITERS " \t\n"

int main(int argc, char** argv);

#endif
