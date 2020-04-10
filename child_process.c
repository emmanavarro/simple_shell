#include "shell.h"

/**
* child_process - create a child process to execute the command
* @env: environment
* @argv: arguments to verify
*/
void child_process(char **env, char **argv)
{
	struct stat st;
	char *str = NULL;

	if (stat(argv[0], &st) == 0)
		str = argv[0];
	else
	{
		str = basic_command(argv[0]);
		if (str == NULL)
			str = split_check(env, argv[0]);
	}
	if (str)
	{
		son = fork();
		if (!son)
		{
			if (execve(str, argv, env) == -1)
				perror("%s: cannot access %s: No such file or directory", str, argv[1]);
		}
		else
			wait(&status);
	}
	else
		perror("%s: command not found", str);
}
