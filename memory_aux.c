#include "shell.h"

/**
 *_memset - function that fills memory with a constant byte.
 *@s: buffer
 *@b: constant byte
 *@n: size
 *
 * Return: s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
 *_calloc - function that allocates memory for an array,
 * @nmemb: size array
 * @size: the size of the memory to print
 * Return:arr
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{

	void *arr;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	arr = malloc(size * nmemb);
	if (!arr)
	{
		return (NULL);
	}
	_memset(arr,  0, (size * nmemb));
	return (arr);
}
