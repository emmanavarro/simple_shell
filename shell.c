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
	(void)ac;
	(void)av;
	char *str = NULL;
	char **array = NULL;
	int out = 1, i = 0, r = 0;

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
				r = child_process(env, array);
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
	}
	return (0);
}
