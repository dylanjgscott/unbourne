/**
 * @author Dylan Scott dsco9564
 */

#ifndef unbourne_h
#define unbourne_h 1

/* size of string buffers */
#define BUF_SIZE 1024

/* size of argument arrays */
#define ARGS_SIZE 1024

/* prompt string */
#define PROMPT "$ "

/* name of shell */
#define SHELL_NAME "unbourne"

/* delimiting charaters in parsing commands */
#define DELIMITERS " \t\n"

/* environment variable storing shell path */
#define SHELL_VAR "SHELL"

/* environment variable storing parent path */
#define PARENT_VAR "PARENT"

/* environment variable storing paths to executables */
#define PATH_VAR "PATH"

/* separator used by path variable */
#define PATH_SEPARATOR ":"

/* directory separator */
#define DIR_SEPARATOR "/"

/* environment variable storing current working dir */
#define CWD_VAR "PWD"

/* command used to redirect stdin */
#define IN_REDIRECT_CMD "<"

/* command used to redirect stdout */
#define OUT_REDIRECT_CMD ">"

/* command used to redirect stdout with append mode */
#define APPEND_REDIRECT_CMD ">>"

/* command used to run in background */
#define BACKGROUND_CMD "&"

/* command used by cls */
#define CLEAR_CMD "clear"

/* command used by dir for getting dir contents */
#define DIR_CMD "ls"

/* options for DIR_CMD */
#define DIR_OPTS "-al"

/* filename of readme file */
#define README_FILENAME "readme"

/* name of more command */
#define MORE_CMD "more"

/* if child_pid is zero, don't wait for child proccesses */
/* this pid is used for SIGTERM handling and PIDWAIT */
pid_t child_pid;

/* stores the path to readme file */
char readme_path[BUF_SIZE];

int main(int argc, char** argv);

#endif
