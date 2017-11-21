#include "shell.h"
/**
 * get_char - reads an input of a character
 *
 * Return: the contents of the buffer one character at a time
 */
int get_char(void)
{
	static char buffer[MAX];
	static int start;
	static int end;
	int c = 0;

	if (start == end)
	{
		c = read(0, buffer, MAX);
		if (c == 0)
			return (EOF);
		start = 0;
		end = c;
	}
	if (c >= 0)
		return (buffer[start++]);
	return (EOF);
}
/**
 * get_line - reads a line from stdin
 *
 * Return: pointer to the line
 */
char *get_line(void)
{
	char *line;
	int c, index, buffer_size;

	buffer_size = BUF_SIZE;
	line = malloc(sizeof(char) * BUF_SIZE);
	if (line == NULL)
	{
		perror("Failed to allocate memory\n");
		return (NULL);
	}
	index = 0;
	while (1)
	{
		c = get_char();
		if (c == EOF)
		{
			line[index] = EOF;
			return (line);
		}
		else if (c == '\n')
		{
			line[index] = '\0';
			return (line);
		}
		else
			line[index] = c;
		index++;
		if (index >= BUF_SIZE)
		{
			buffer_size += BUF_SIZE;
			line = _realloc(line, buffer_size - BUF_SIZE, buffer_size);
			if (line == NULL)
			{
				perror("Failed to allocate memory\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
