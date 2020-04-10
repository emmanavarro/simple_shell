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
	int out = 1, i = 0;

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
				child_process(env, array);
				free(str);
			}
		}
	}
	while (array && array[i])
		free(array[i++]);
	free(array);
	free(str);
	return (0);
}
