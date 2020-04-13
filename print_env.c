#include "shell.h"

/**
 * print_env - print environment variable
 * @env: environment variable
 * Return: 0 success
 */
int print_env(char **env)
{
	int i = 0;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	printf("ESTA EN ENV\n");
	return (0);
}

