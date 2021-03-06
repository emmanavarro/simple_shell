#include "shell.h"

/**
 * child_process - create a child process to execute the command
 * @env: environment
 * @argv: arguments to verify
 * @av: program name
 * @count: counter to executions
 * Return: 0 success, 127 error
 */
int child_process(char **env, char **argv, char *av, int count)
{
	struct stat st;
	char *str = NULL, err_msg[100];
	int status = 0, i = 0;
	pid_t son;

	if (stat(argv[0], &st) == 0)
		str = argv[0];
	else
		if (str == NULL)
			str = split_check(env, argv[0]), i = 1;
	if (str)
	{
		son = fork();
		if (!son)
		{
			if (execve(str, argv, env) == -1)
			{
				sprintf(err_msg, "%s: %d: %s: not found\n", av, count, argv[0]);
				write(2, err_msg, _strlen(err_msg));
				(i == 1) ? free(str) : (void) i;
				exit(2);
			}
		}
		else
		{
			wait(&status), (i == 1) ? free(str) : (void) i;
			return (status >> 8);
		}
	}
	else
	{
		sprintf(err_msg, "%s: %d: %s: not found\n", av, count, argv[0]);
		write(2, err_msg, _strlen(err_msg));
		(i == 1) ? free(str) : (void) i;
		return (127);
	}
	return (0);
}
