/**
 * @author Dylan Scott dsco9564
 */

#ifndef shell_h
#define shell_h 1

#define BUF_SIZE 1024
#define ARGS_SIZE 1024
#define PROMPT "$ "
#define SHELL_NAME "unbourne"
#define DELIMITERS " \t\n"
#define SHELL_VAR "SHELL"
#define PATH_VAR "PATH"
#define PATH_SEPARATOR ":"
#define DIR_SEPARATOR "/"
#define CWD_VAR "PWD"
#define IN_REDIRECT_CMD "<"
#define OUT_REDIRECT_CMD ">"
#define APPEND_REDIRECT_CMD ">>"
#define BACKGROUND_CMD "&"


int main(int argc, char** argv);

#endif
