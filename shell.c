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
	int out = 1, i = 0, r = 0, count = 1;
	(void)ac;
	(void)av;

	while (out == 1)
	{
		str = prompt();

		if (str == NULL)
		{
			out = 2;
		}
		else
		{
			array = get_token(str);

			if (str && _strncmp(str, "\n", 1) && array[0])
			{
				r = child_process(env, array, av[0], count);
				if (r != 0)
					return (r);
				free(str);
				i = 0;
				while (array && array[i])
				{
					free(array[i++]);
				}
				free(array);
			}
		}
		count++;
	}
	return (0);
}
