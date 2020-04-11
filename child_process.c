#include "shell.h"

/**
 * child_process - create a child process to execute the command
 * @env: environment
 * @argv: arguments to verify
 * Return: 0 success, 127 error
 */
int child_process(char **env, char **argv)
{
	struct stat st;
	char *str = NULL;
	int status = 0;
	pid_t son;

	if (stat(argv[0], &st) == 0)
		str = argv[0];
	else
	{
		str = basic_command(argv[0]);

		if (str == NULL)
		{
			str = split_check(env, argv[0]);
		}
	}
	if (str)
	{
		son = fork();
		if (!son)
		{
			if (execve(str, argv, env) == -1)
				perror("cannot access, No such file or directory");
				return (127);
		}
		else
			wait(&status);
	}
	else
		perror("command not found");
	return (0);
}
