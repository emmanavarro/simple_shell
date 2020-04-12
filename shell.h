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

/**
* struct command - struct that contains the basic commands
* @name: name of the command
* @path: location of the command
*/
typedef struct command
{
	char *name;
	char *path;
} com_s;

char *_strcpy(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_memset(char *s, char b, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);

char *prompt();
char **get_token(char *str);
char *find_path(char **env);
char *split_check(char **enviro, char *str);
char *basic_command(char *str);
int child_process(char **env, char **argv, char *av, int count);

#endif /* _SHELL_H*/
