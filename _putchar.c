#include "shell.h"
/**
 * _putchar - prints a character to stdout
 * @c: character
 * Return: 0 (success), -1 otherwise
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}
