#include "shell.h"
/**
 * print_error - prints error messages
 * @prog: program name
 * @loop_count: shell loop count
 * @line: command line
 *
 * Return: void
 */
void print_error(char *prog, int loop_count, char *line)
{
	char *loop;

	loop = num_to_string(loop_count + 1);
	write(2, prog, _strlen(prog));
	write(2, ": ", 2);
	write(2, loop, _strlen(loop));
	write(2, ": ", 2);
	write(2, line, _strlen(line));
	write(2, ": ", 2);
	if (errno == EACCES)
	{
		write(2, "Permission denied\n", 18);
	}
	else
	{
		write(2, "not found\n", 10);
	}
}

