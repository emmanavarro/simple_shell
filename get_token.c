#include "shell.h"
/**
 * _strlen - returns the length of a string.
 *@s: char
 * Return: i
 */
int _strlen(char *s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 *
 */
char **get_token(char *str)
{
	char **tokens = NULL;
	char *tok = NULL;
	int count;
	char *buff = NULL;
	buff = malloc(sizeof(char) * _strlen(str) + 1);
	if (buffer != NULL)
		return (NULL);
	_strcpy(buff, str);
	tok = strtok(str, " \t\n\r");
	while (tok)
	{
		count++;
		tok = strtok(NULL, " \t\n\r");
	}
}
