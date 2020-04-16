#ifndef _SHELL_H_
#define _SHELL_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

/**
* struct command - struct that contains the basic commands
* @name: name of the command
* @fun: pointer to a function
*/
typedef struct command
{
	char *name;
	int (*fun)(char **env);
} com_s;

char *_strcpy(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_memset(char *s, char b, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
void free_mem(char **array);
void sign_c(int sig);

char *prompt();
char **get_token(char *str);
char *find_path(char **env);
char *split_check(char **enviro, char *str);
int (*basic_command(char *str))(char **env);
int child_process(char **env, char **argv, char *av, int count);
int print_env(char **env);

#endif /* _SHELL_H*/
