#include "shell.h"

/**
 * printprompt - prints the prompt if not in interactive mode
 * @PS1 - prompt
 */
void printprompt(char *prompt)
{
	if (prompt == NULL)
		return;
	write(1, prompt, _strlen(prompt));
}

/**
 * builtins - runs builtins
 * @line: builtin to run
 *
 * Return: 0 if success, 1 otherwise
 */
int builtins(char *line)
{
	if (line == NULL)
		return (1);
	if (_strcmp(line, "env") == 0)
	{
		printenv();
		return (0);
	}
	return (1);
}

/**
 * execute - executes commands
 * @tokens: command and arguments
 * @st: pointer to status
 *
 * Return: 0 if success, 1 otherwise
 */
int execute(char **tokens, struct stat *st)
{
	char *path;

	path = getpath(tokens[0]);
	if (path != NULL && stat(path, st) == 0)
	{
		execv(path, tokens);
		return (0);
	}
	return (1);
}

/**
 * run - creates child
 *
 * Return: 0 for child, -1 for error, anything else for parent
 */
pid_t run(char *prog, char *line, char **tokens)
{
	pid_t child;
	int status;
	struct stat st;

	child = fork();
	if (child == -1)
	{
		errno = ECHILD, perror(prog);
		free(line), free(tokens);
		return (-1);
	}
	if (child == 0)
	{
		if (builtins(line) == 1)
			if (execute(tokens, &st) == 1)
				perror(prog);
	}
	else
		wait(&status);
	return (child);
}
