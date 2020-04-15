#include "shell.h"

/**
* main - simple shell
* @ac: number of arguments
* @av: arguments
* @env: environment
* Return: 0 success
*/
int main(int ac, char *av[], char **env)
{
	char *str = NULL;
	char **array = NULL;
	int out = 1, count = 1, r = 0;
	(void)ac;
	(void)av;

	while (out == 1)
	{
		str = prompt();
		if (str == NULL)
			out = 2;
		else
		{
			if (_strncmp(str, "env", 3) == 0)
			{
				print_env(env);
				free(str);
			}
			else
			{
				array = get_token(str);
				if (str && _strncmp(str, "\n", 1) && array[0])
				{
					r = child_process(env, array, av[0], count);
					free_mem(array);
					free(str);
				}
				else
				{
					free_mem(array);
					free(str);
				}
			}
		}
		count++;
	}
	return (r);
}
