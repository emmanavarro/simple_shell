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

char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, int n);
char *_memset(char *s, char b, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_strcat(char *dest, char *src);
int _strlen(char *s);

char *prompt();
char **get_token(char *str);
char *find_path(char **env);
char **split(char **enviro);
char *check_path(char **ev, char*str);

#endif /* _SHELL_H*/
