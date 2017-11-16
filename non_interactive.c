#include "shell.h"
/**
 * non_interactive_mode - hands commands passed through a pipe
 *
 * Return: 0 if success, anything else for error
 */
int non_interactive_mode(void)
{
	pid_t child;
	char *line, *path;
	char **tokens;
	int status;
	struct stat st;

	line = get_line();
	tokens = tokenize_line(line, " ");
	if (_strcmp(tokens[0], "exit") == 0)
	{
		if (tokens[1] != NULL)
			return (_atoi(tokens[1]));
		free(line), free(tokens);
		return (0);
	}
	child = fork();
	if (child == -1)
	{
		free(line), free(tokens);
		return (-1);
	}
	else if (child == 0)
	{
		if (_strcmp(line, "env") == 0)
			printenv();
		path = getpath(tokens[0]);
		if (path == NULL || stat(path, &st) != 0)
		{
			free(line), free(tokens);
			return (-1);
		}
		else
		{
			free(line);
			execv(path, tokens);
		}
	}
	else
	{
		wait(&status);
		free(line), free(tokens);
	}
	return (0);
}
