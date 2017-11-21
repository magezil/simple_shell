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
	char *line, **tokens;
	int status, loop_count = 0;

	signal(SIGINT, SIG_IGN);
	child = getpid();
	while (child > 0)
	{
		if (isatty(0))
			printprompt("simple_shell$ ");
		line = get_line();
		if (line == NULL)
		{
			errno = EINVAL, perror(argv[0]);
			return (-1);
		}
		else if (line[0] == EOF)
		{
			free(line);
			if (isatty(0))
				write(1, "\n", 1);
			return (0);
		}
		else if (line[0] != '\0' && _strcmp(line, ".") && _strcmp(line, ".."))
		{
			tokens = tokenize_line(line, DELIM);
			if (_strcmp(tokens[0], "exit") == 0)
			{
				status = tokens[1] == NULL ? 0 : _atoi(tokens[1]);
				free(line), free(tokens);
				return (status);
			}
			child = run(argv[0], line, tokens, loop_count);
			free(tokens);
		}
		free(line);
		loop_count++;
	}
	return (child == -1 ? -1 : 0);
}
