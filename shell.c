#include "shell.h"
/**
 * main - simple shell program that takes user input and interprets it as unix
 * commands
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	pid_t child;
	char *line;
	char *path;
	char *PS1;
	char **tokens;
	int status;
	struct stat st;
	(void) argc;

	if (!isatty(0))
	{
		status = non_interactive_mode();
		if (status == -1)
		{
			perror(argv[0]);
			return -1;
		}
		return (status);
	}
	while (1)
	{
		PS1 = "simple_shell$ ";
		write(1, PS1, _strlen(PS1));
		line = get_line();
		if (line == NULL)
		{
			perror("Invalid line");
			return (-1);
		}
		else if (line[0] == EOF)
		{
			write(1, "\n", 1);
			free(line);
			break;
		}
		else if (line[0] != '\0')
		{
			tokens = tokenize_line(line, " ");
			if (_strcmp(tokens[0], "exit") == 0)
			{
				if (tokens[1] != NULL)
					return (atoi(tokens[1]));
				return (0);
			}
			child = fork();
			if (child == -1)
			{
				perror("Failed to create process");
				free(line);
				return (-1);
			}
			else if (child == 0)
			{
				if (_strcmp(line, "env") == 0)
				{
					printenv();
					break;
				}
				path = getpath(tokens[0]);
				if (path == NULL || stat(path, &st) != 0)
				{
					perror(argv[0]);
					free(line);
					free(tokens);
					break;
				}
				else
					execv(path, tokens);
			}
			else
			{
				wait(&status);
				free(line);
				free(tokens);
			}
		}
	}
	return (0);
}
