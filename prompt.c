#include "shell.h"

/**
  * prompt - display the prompt
  *
  * Return: input line
  */
char *prompt(void)
{
	char *line_buffer;
	size_t length;
	ssize_t read;

	write(STDOUT_FILENO, "cisfun$ ", 8);

	read = getline(&line_buffer, &length, stdin);

	if (read == EOF)
	{
		perror("Error: the command couldn't be read");
		write(STDOUT_FILENO, "\n", 1);
		return (NULL);
	}

	if (_strcmp(line_buffer, "exit\n") == 0)
	{
		free(line_buffer);
		exit(0);
	}
	return (line_buffer);
}
