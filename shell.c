#include "shell.h"
/**
 * main - simple shell program that takes user input and interprets it as unix
 * commands
 * @argc: number of command line arguments
 * @argv: list of command line arguments
 *
 * Return: 0 (success)
 */
int main(__attribute__((unused))int argc, char *argv[])
{
	pid_t child;
	char *line, *path, *PS1, **tokens;
	int status;
	struct stat st;

	child = getpid();
	while (child != 0)
	{
		if (isatty(0))
		{
			PS1 = "simple_shell$ ";
			write(1, PS1, _strlen(PS1));
		}
		line = get_line();
		if (line == NULL)
		{
			errno = EINVAL, perror(argv[0]);
			return (-1);
		}
		else if (line[0] == EOF)
			write(1, "\n", 1);
		else if (line[0] != '\0' && strcmp(line, ".") && strcmp(line, ".."))
		{
			tokens = tokenize_line(line, " ");
			if (_strcmp(tokens[0], "exit") == 0)
			{
				status = tokens[1] == NULL ? 0 : _atoi(tokens[1]);
				free(line), free(tokens);
				return (status);
			}
			child = fork();
			if (child == -1)
			{
				errno = ECHILD, perror(argv[0]);
				free(line), free(tokens);
				return (-1);
			}
			else if (child == 0)
			{
				if (_strcmp(line, "env") == 0)
					printenv();
				else
				{
					path = getpath(tokens[0]);
					if (path != NULL && stat(path, &st) == 0)
						execv(path, tokens);
					perror(argv[0]);
				}
			}
			else
				wait(&status);
			free(tokens);
		}
		free(line);
		if (!isatty(0) || line[0] == EOF)
			break;
	}
	return (0);
}
