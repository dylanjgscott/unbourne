/**
 * @author Dylan Scott dsco9564
 */

#ifndef unbourne_h
#define unbourne_h 1

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
#define CLEAR_CMD "clear"
#define PWD_VAR "PWD"

/* if child_pid is zero, don't wait for child proccesses */
/* this pid is used for SIGTERM handling and PIDWAIT */
pid_t child_pid;

/* stores the path to readme file */
char readme_path[BUF_SIZE];

int main(int argc, char** argv);

#endif
