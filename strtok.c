#include "shell.h"
/**
 * _strdup - duplicates a string
 * @s: string
 *
 * Return: pointer to duplicate of s
 */
char *_strdup(char *s)
{
	unsigned int len, i;
	char *buffer;

	len = _strlen(s);
	buffer = malloc(sizeof(char) * len + 1);
	if (buffer == NULL)
	{
		perror("Failed to allocate memory");
		return (NULL);
	}

	i = 0;
	while (s[i] != '\0')
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
int is_delim(char c, const char *delim)
{
	unsigned int i = 0;

	while (delim[i] != '\0')
	{
		if (c == delim[i])
			return (1);
		i++;
	}
	return (0);
}
/**
 * _strlen - computes the length of a string
 * @s: string to compute
 *
 * Return: length of string, -1 if error
 */
int _strlen(char *s)
{
	int len;

	if (s == NULL)
		return (-1);
	for (len = 0; s[len] != '\0'; len++)
		;
	return (len);
}
/**
 * _strtok - extracts tokens from a string
 * @str: string to extract from
 * @delim: delimiters
 *
 * Return: pointer to the next token, or NULL if there are no more tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *token;
	static int i;
	int start = i;

	if (str != NULL)
		token = str;
	

	while (token[i] != '\0')
	{
		if (is_delim(token[i], delim) == 1)
		{
			token[i] = '\0';
			i++;
			if (token[start] != '\0')
				return (&token[start]);	
			else
			{
				start = i;
				i--;
				break;
			}
		}
		i++;
	}
	token[i] = '\0';

	if (token[start] == '\0')
		return (NULL);
	return (&token[start]);
}

int main(void)
{
	char *token;
	char **tokens;
	char *line;
	int i = 0;

	line = _strdup("hello wor-ld");
	tokens = malloc(sizeof(char *) * 10);
	token = _strtok(line, " -");
	printf("1st token: [%s]\n", token);
	while (token != NULL)
	{
		tokens[i] = token;
		token = _strtok(NULL, " -");
		i++;
	}
	tokens[i] = NULL;

	i = 0;
	while (tokens[i] != NULL)
	{
		printf("tokens[%d]: [%s]\n", i, tokens[i]);
		i++;
	}
	return (0);
}
