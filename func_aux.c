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
/**
 *_strcmp -  function that compares two strings.
 *@s1: string
 *@s2: string
 * Return: diferencia
 */
int _strcmp(char *s1, char *s2)
{
	int i, diferencia;

	i = 0;
	diferencia = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && diferencia == 0)
	{
		if (s1[i] != s2[i])
		{
			diferencia = s1[i] - s2[i];
		}
		i++;

	}
	return (diferencia);
}
/**
 * _strcpy - unction that copies the string pointed to by src
 *@dest: char
 *@src:_ char
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{

	int i = 0, j;

	while (src[i] != '\0')
	{
		i++;
	}
	for (j = 0; j <= i; j++)
	{
		dest[j] = src[j];
	}
	return (dest);
}
/**
 *_strcat -  function that concatenates two strings.
 *@dest: char
 *@src: char
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	for (j = 0;  src[j] != '\0'; j++, i++)
	{
		dest[i] = src[j];
	}
	return (dest);
}

