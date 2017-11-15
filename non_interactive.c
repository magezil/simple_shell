#include "shell.h"
/**
 * non_interactive_mode - hands commands passed through a pipe
 *
 * Return: void
 */
void non_interactive_mode(void)
{
	pid_t child;
	char *line;
	char **tokens;
	int status;
	struct stat st;

	line = get_line();
	tokens = tokenize_line(line);
	child = fork();
	if (child == -1)
	{
		perror("Failed to create process");
		free(line);
		return;
	}
	else if (_strcmp(line, "exit") == 0)
	{
		return;
	}
	else if (child == 0)
	{
		if (_strcmp(line, "env") == 0)
		{
			printenv();
		}
		else if (stat(tokens[0], &st) != 0)
		{
			perror(line);
			free(line);
			free(tokens);
		}
		else
			execv(tokens[0], tokens);
	}
	else
	{
		wait(&status);
		free(line);
		free(tokens);
	}
	return;	
}
