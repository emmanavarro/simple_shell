#include "shell.h"

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
char **split(char **enviro)
{
	char *cpy_path = find_path(enviro);
	char **store_dir = NULL;
	char *tok = NULL;
	int pos = 0;

	tok = strtok(cpy_path, ":");
	while (tok != NULL)
	{
		_strcpy(store_dir[pos], tok);
		tok = strtok(NULL, ":");
		pos++;

	}
	return (store_dir);
}

