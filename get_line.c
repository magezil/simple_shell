#include "shell.h"
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
		c = getchar();
		if (c == EOF || c == '\n')
		{
			if (c == EOF)
			{
				line[index] = EOF;
				return (line);

			}
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
				fprintf(stderr, "Failed to allocate memory\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
