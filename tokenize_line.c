#include "shell.h"
/**
 * tokenize_line - breaks a line up into tokens
 * @line: line to break up
 *
 * Return: pointer to an array of strings (tokens)
 */
char **tokenize_line(char *line)
{
	char **args;
	char *token;
	unsigned int index = 0;

	if (line == NULL)
	{
		fprintf(stderr, "Error\n");
		exit(EXIT_FAILURE);
	}
	args = malloc(sizeof(char *) * ARG_SIZE);
	if (args == NULL)
	{
		fprintf(stderr, "Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " ");
	while (token != NULL)
	{
		args[index] = token;
		token = strtok(NULL, " ");
		index++;
	}
	args[index] = NULL;
	return (args);
}
