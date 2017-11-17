#include "shell.h"
/**
 * get_char - reads an input of a character
 *
 * Return: the character read casted as an int
 */
int get_char(void)
{
	static char buffer[MAX];
	static size_t start;
	static size_t end;
	int c = 0;

	start = 0;
	end = 0;
	if (start == end) /* buffer is empty */
	{
		c = read(0, buffer, 1024);
		if (c == 0)
			return (EOF);
		start = 0;
		end = c;
	}
	if (c >= 0)
	{
		start++;
		return (buffer[start - 1]);
	}
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
