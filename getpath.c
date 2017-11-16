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
	if (name[0] == '/' || name[0] == '.')
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
			free(tokens);
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

/**
 * _strcpy - copy a string
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to copy
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);
	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - concatinate two strings
 * @dest: destination string
 * @src: string to concat
 *
 * Return: pointer to copy
 */
char *_strcat(char *dest, char *src)
{
	int i, len;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);

	for (len = 0; dest[len] != '\0'; )
		len++;
	for (i = 0; src[i] != '\0'; i++)
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}
