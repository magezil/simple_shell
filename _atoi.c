#include "shell.h"
/**
 * _atoi - convert a string to a number
 * @s: string to convert
 *
 * Return: number or 0 if string cannot be converted
 */
int _atoi(char *s)
{
	int found = 0;
	unsigned int num = 0;
	int n = 1;

	while (*s != '\0')
	{
		if (*s == '-')
			n *= -1;
		else if (*s >= '0' && *s <= '9')
		{
			if (!found)
				found = 1;
			num = num * 10 + (*s - '0');
		}
		else
			return (0);
		s++;
	}
	return (num * n);
}
