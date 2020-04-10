#include "shell.c"

/**
 * basic_command - exchange the path
 * @str: recieved command
 * Return: command location
 */

char *basic_command(char *str)
{
	int pos = 0;

	com_s command[] = {
			{"rm", "/bin/rm"},
			{"rmdir", "/bin/rmdir"},
			{"mkdir", "/bin/mkdir"},
			{"pwd", "/bin/pwd"},
			{"ls", "/bin/ls"},
			{"echo", "/bin/echo"},
			{"cat", "/bin/cat"},
			{"mv", "/bin/mv"},
			{"chmod", "/bin/chmod"},
			{"kill", "/bin/kill"},
			{NULL, NULL}};

	while (command[pos].name != NULL)
	{
		if (_strncmp(str, command[pos].name, _strlen(command[pos].name)) == 0)
		{
			return (comman[pos].path);
		}
		pos++;
	}
	return (NULL);
}
