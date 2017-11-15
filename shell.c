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
	char **tokens;
	int status;
	struct stat st;
	(void) argc;

	while (1)
	{
		printf("simple_shell$ ");
		line = get_line();
		if (line == NULL)
		{
			perror("Invalid line");
			return(-1);
		}
		else if (line[0] == EOF)
		{
			break;
		}
		else if (line[0] != '\0')
		{
			tokens = tokenize_line(line);
			child = fork();
			if (child == -1)
			{
				perror("Failed to create process");
				return(-1);
			}
			else if (child == 0)
			{
				/* NOT FOUND */
				if (stat(tokens[0], &st) != 0)
				{
					fprintf(stderr, "%s: command not found: %s\n",
							argv[0], tokens[0]);
					return (-1);
				}
				else
				{
					execv(tokens[0], tokens);
				}
			}
			else
			{
				wait(&status);
				free(line);
				free(tokens);
			}
		}
	}
	free(line);
	free(tokens);
	return (0);
}
