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
	char **store_dir;
	char *tok = NULL;
	char *dir = NULL;
	int pos = 0;
	struct stat st;

	cpy_path = find_path(enviro);
	store_dir = _calloc(8, sizeof(char *));

	if (store_dir == NULL)
	{
		return (NULL);
	}
	tok = strtok(cpy_path, ":");
	while (tok != NULL)
	{
		dir = _strdup(tok);
		store_dir[pos] = dir;

		path = _strcat(store_dir[pos], "/");
		path = _strcat(store_dir[pos], str);

		if (stat(path, &st) == 0)
		{
			while (store_dir && store_dir[pos])
				free(store_dir[pos--]);
			free(store_dir);
			return (path);
		}
		tok = strtok(NULL, ":");
		pos++;
	}

	return (NULL);
}
