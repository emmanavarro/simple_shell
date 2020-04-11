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
	int status = 0;
	pid_t son;
	int d = 0;
	int p;

	if (stat(argv[0], &st) == 0)
		str = argv[0];
	else
	{
		str = basic_command(argv[0]);
		printf("encontre la ruta en command %s\n", str);
		if (str == NULL)
		{
			printf("estoy en path \n");
			str = split_check(env, argv[0]);
			d = 1;
			printf("cambie mi valor y soy D: %d\n",d);
		}
	}
	p = 0;

	while(argv[p] != NULL)
	{
		printf("estoy en child argv: %s\n", argv[p]);
		p++;

	}

	son = fork();
	if (son == 0)
	{
		if (str)
		{
			if (execve(str, argv, env) == -1)
			{
				perror("cannot access, No such file or directory");
				if (d == 1)
				{
					printf("se libero");
					
				}
			}
			else
			{
				printf("se libero 2");
				free(str);
			}
		}
		else
		{
			free(str);
		}

			wait(&status);
			free(str);
	}
	else
	{
		wait(&status);
	}
	p = 0;
	while(argv[p] != NULL)
	{
		 printf("estoy en child argv: %s\n", argv[p]);
		 p++;
	}	

		printf("ya no estoy aqui\n");
}
