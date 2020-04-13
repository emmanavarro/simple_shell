#include "shell.h"

/**
 * basic_command - exchange the path
 * @str: recieved command
 * Return: command location
 */

int (*basic_command(char *str))(char **env)
{
	int pos = 0;

	com_s command[] = {
			{"env", print_env},
			{NULL, NULL}};

	while (command[pos].name != NULL)
	{
		if (_strncmp(str, command[pos].name, _strlen(command[pos].name)) == 0)
		{
			return (command[pos].fun);
		}
		pos++;
	}
	return (NULL);
}
