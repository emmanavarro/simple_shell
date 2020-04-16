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
	return (0);
}

/**
* sign_c - sends a signal when ctrl + C is entered
* @sig: input
*/
void sign_c(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\ncisfun$ ", 9);
}