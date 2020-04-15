#include "shell.h"

/**
* free_mem - free the memory of double pointer
* @array: double pointer to be free
*/
void free_mem(char **array)
{
	int i = 0;

	while (array && array[i])
	{
		free(array[i++]);
	}
	free(array);
}
