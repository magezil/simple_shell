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
