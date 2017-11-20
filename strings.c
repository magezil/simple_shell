#include "shell.h"
/**
 * _strcmp - compates two string
 * @s1: string 1
 * @s2: string 2
 *
 * Return: -value if s1 is less than s2, 0 is they are equal, +value if s1 is
 * greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int len_diff;

	len_diff = _strlen(s1) - _strlen(s2);
	if (len_diff != 0)
		return (len_diff);
	while (s1[i])
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * _strlen - computes the length of a string
 * @s: string to compute
 *
 * Return: length of string, -1 if error
 */
int _strlen(char *s)
{
	int len;

	if (s == NULL)
		return (-1);
	for (len = 0; s[len] != '\0'; len++)
		;
	return (len);
}

/**
 * _strcpy - copy a string
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to copy
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);
	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - concatinate two strings
 * @dest: destination string
 * @src: string to concat
 *
 * Return: pointer to copy
 */
char *_strcat(char *dest, char *src)
{
	int i, len;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);

	for (len = 0; dest[len] != '\0'; )
		len++;
	for (i = 0; src[i] != '\0'; i++)
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}

/**
 * _strfind - find a character in a string
 * @c: character to find
 * @s: string to seach
 *
 * Return: 1 if found, 0 otherwise
 */
int _strfind(char c, char *s)
{
	if (s == NULL)
		return (0);

	while (*s != '\0')
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}
