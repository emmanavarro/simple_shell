#include "shell.h"
/**
 * get_token - get the command line and tokenize it
 * @str: command line
 *
 * Return: tokenized command
 */
char **get_token(char *str)
{
	char **tokens = NULL;
	char *tok = NULL;
	int count = 0, i;
	char *buff = NULL;

	buff = malloc(sizeof(char) * _strlen(str) + 1);
	if (buff == NULL)
		return (NULL);
	_strcpy(buff, str);
	tok = strtok(str, " \t\n\r\a");
	while (tok)
	{
		count++;
		tok = strtok(NULL, " \t\n\r\a");
	}
	tokens = _calloc((count + 2), sizeof(char *));
	if (tokens == NULL)
	{
		free(buff);
		return (NULL);
	}
	tok = strtok(buff, " \t\n\r\a");
	count = 0;
	while (tok)
	{
		tokens[count] = malloc(sizeof(char) * _strlen(tok) + 2);
		if (tokens[count] == NULL)
		{
			for (i = 0; tokens[count]; i++)
				free(tokens[count]);
			free(tokens), free(buff);
			return (NULL);
		}
		_strcpy(tokens[count], tok);
		count++;
		tok = strtok(NULL, " \t\n\r\a");
	}
	tokens[count] = NULL;
	free(buff);
	return (tokens);
}
