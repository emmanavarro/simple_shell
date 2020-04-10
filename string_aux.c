#include "shell.h"
/**
 * _strlen -  returns the length of a string.
 *@s: char
 * Return: i
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);

}
/**
 *_strncmp -  function that compares two strings.
 *@s1: string
 *@s2: string
 *@n: number of characters
 * Return: diferencia
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i, diferencia;

	i = 0;
	diferencia = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && diferencia == 0 && i < n)
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
	dest[i] = '\0';
	return (dest);
}
/**
 *_strdup - function that returns a pointer
 *@str: char
 * Return: s
 */
char *_strdup(char *str)
{
	int j, l;
	char *s;

	if (!str)
	{
		return (NULL);
	}

	l = _strlen(str) + 1;

	s = malloc(l * sizeof(char));
	if (!s)
	{
		return (NULL);

	}

	for (j = 0; j < l; j++)
	{
		s[j] = str[j];
	}
	return (s);
}
