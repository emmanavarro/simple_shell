#include "shell.h"

/**
 * find_path - find the environment variable PATH
 * @env: environment variable
 * Return: PATH
 */

char *find_path(char **env)
{
	int i = 0;
	char *cpy_env = NULL;

	if (env == NULL)
		return (NULL);

	for (i = 0; env[i] != NULL; i++)
		if (_strncmp(env[i], "PATH=", 5) == 0)
			break;
	cpy_env = _strdup(env[i]);
	return (cpy_env);
}
/**
 * split_check - divide the elements and check the path
 * @enviro: environment variable
 * @str: element to search in the path
 * Return: path
 */
char *split_check(char **enviro, char *str)
{
	char *cpy_path = NULL, *path = NULL, *cpy_env = NULL;
	char *tok = NULL;
	struct stat st;

	cpy_env = find_path(enviro);
	if (cpy_env == NULL)
		return (NULL);
	cpy_path = _strdup(cpy_env);
	free(cpy_env);
	tok = strtok(cpy_path, ":");
	while (tok != NULL)
	{
		path = malloc(sizeof(char *) * (_strlen(tok) + 1 + _strlen(str)));
		if (path == NULL)
		{
			free(path);
			return (NULL);
		}
		_strcpy(path, tok);
		_strcat(path, "/");
		_strcat(path, str);
		if (stat(path, &st) == 0)
		{
			free(cpy_path);
			return (path);
		}
		free(path);
		tok = strtok(NULL, ":");
	}
	free(cpy_path);
	return (NULL);
}
