#include "shell.h"

void split_path(char *str, char **env)
{
	printf ("llego");
	int j = 0;
	char *cpy_env = NULL, *store_path = NULL;

	cpy_env = malloc(sizeof(char) * _strlen(env[j])+ 1);

	if (cpy_env == NULL)
	{
		printf("null");
	}
	_strcpy(cpy_env, env[j]);

	store_path = strtok(cpy_env, "=");

	while (_strncmp("PATH", store_path, 4) && store_path  && env[j])
	{
		 _strcpy(cpy_env, env[j]);
		store_path = strtok(cpy_env, "=");
		j++;
	}
	printf("copy: %s\n", cpy_env);
	store_path = strtok(NULL, ":");



	/*while(store_path != NULL)
	{
		store_path= strtok(NULL, ":");
		_strcat(store_path, "/");
		_strcat(store_path, str);
	}*/

	printf("lo hizo store:%s  \n", store_path);
}
