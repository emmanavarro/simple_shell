#include "shell.h"

/**
 * find_path - find the environment variable PATH
 * @env: environment variable
 * Return: PATH
 */

char *find_path(char **env)
{
	int j = 0;
	char *cpy_env = NULL, *store_path = NULL;

	cpy_env = env[j];

	store_path = strtok(cpy_env, "=");

	while (_strncmp("PATH", store_path, 4) && store_path  && env[j])
	{
		cpy_env = env[j];
		store_path = strtok(cpy_env, "=");
		j++;
	}
	store_path = strtok(NULL, "\n");
	return (store_path);
}
/**
 * split_check - divide the elements and check the path
 * @enviro: environment variable
 * @str: element to search in the path
 * Return: path
 */
char *split_check(char **enviro, char *str)
{
	char *cpy_path = NULL, *path = NULL;
	char *tok = NULL;
	struct stat st;

	cpy_path = find_path(enviro);
	tok = strtok(cpy_path, ":");
	while (tok != NULL)
	{
		path = malloc(sizeof(char *) * (_strlen(tok) + 1 + _strlen(str)));
		if (path == NULL)
		{
			return (NULL);
		}


	         _strcpy(path, tok);
		_strcat(path, "/");
		_strcat(path, str);
		printf("ES EL PATH: %s\n", path);

		if (stat(path, &st) == 0)
		{
			return (path);
		}
		free(path);
		tok = strtok(NULL, ":");
	}

	return (NULL);
}
