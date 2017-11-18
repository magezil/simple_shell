#include "shell.h"
/**
 * getpath - gets the full pathname of given command
 * @name: name of command
 *
 * Return: full pathname of command on PATH, NULL if not found
 */
char *getpath(char *name)
{
	char *path;
	char temp[BUF_SIZE] = {'\0'};
	char **tokens;
	int i;
	struct stat st;

	if (name == NULL)
		return (NULL);
	if (_strfind('/', name) || _strfind('.', name))
		return (name);
	path = malloc(BUF_SIZE);
	if (path == NULL)
		return (NULL);
	_strcpy(path, getenv("PATH"));
	tokens = tokenize_line(path, ":");
	for (i = 0; tokens[i] != NULL; i++)
	{
		_strcpy(temp, tokens[i]);
		_strcat(temp, "/");
		_strcat(temp, name);
		if (stat(temp, &st) == 0)
		{
			name = temp;
			return (name);
		}
	}
	/* not found */
	free(tokens);
	return (NULL);
}

/**
 * _getenv - gets environment variable
 * @name: name of env variable to get
 *
 * Return: pointer to environment variable
 */
char *_getenv(const char *name)
{
	char *env;
	int i, j;

	if (name == NULL)
		return (NULL);
	for (i = 0; environ[i] != NULL; i++)
	{
		env = environ[i];
		for (j = 0; name[j] != '\0'; j++)
		{
			if (name[j] != *env)
				break;
			env++;
		}
		if (name[j] == '\0' && *env == '=')
		{
			env++;
			return (env);
		}
	}
	/* no match */
	return (NULL);
}
