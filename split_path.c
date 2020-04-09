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
char *split(char **enviro, char *str)
{
	char *cpy_path = NULL, *path = NULL;
	cpy_path = find_path(enviro);
	char **store_dir;
	char *tok = NULL;
	char *dir = NULL;
	int pos = 0;
	struct stat st;
	store_dir = _calloc(8, sizeof(char *));

	if (store_dir == NULL)
	{
		return NULL;
	}
	tok = strtok(cpy_path, ":");
	while (tok != NULL)
	{
		dir = _strdup(tok);
		store_dir[pos] = dir;
		tok = strtok(NULL, ":");
		pos++;
	}
	pos = 0;
	while(store_dir[pos] != NULL)
	{
		path = _strcat(store_dir[pos], "/");
		path = _strcat(store_dir[pos], str);
		if (stat(path, &st) == 0)
			return (path);
		pos++;
	}
	while(store_dir && store_dir[pos])
		free(store_dir[pos--]);
	free(store_dir);
	return (NULL);
}
