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

	if (!isatty(0))
	{
		non_interactive_mode();
	}
	else
	{
		while (1)
		{
			printf("simple_shell$ ");
			line = get_line();
			if (line == NULL)
			{
				perror("Invalid line");
				return (-1);
			}
			else if (line[0] == EOF)
			{
				printf("\n");
				free(line);
				break;
			}
			else if (line[0] != '\0')
			{
				tokens = tokenize_line(line);
				child = fork();
				if (child == -1)
				{
					perror("Failed to create process");
					free(line);
					return (-1);
				}
				else if (child == 0)
				{
					if (stat(tokens[0], &st) != 0)
					{
						perror(argv[0]);
						free(line);
						free(tokens);
						break;
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
			}
		}
	}
	return (0);
}
