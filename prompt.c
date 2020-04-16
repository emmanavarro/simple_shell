#include "shell.h"

/**
  * prompt - display the prompt
  *
  * Return: input line
  */
char *prompt()
{
	char *line_buffer = NULL;
	size_t length;
	ssize_t read;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "cisfun$ ", 8);
	}

	read = getline(&line_buffer, &length, stdin);

	if ((read == EOF) || (_strncmp(line_buffer, "exit\n", 4) == 0))
	{
		free(line_buffer);
		if (read == EOF && isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		return (NULL);
	}
	return (line_buffer);
}
