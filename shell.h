#ifndef SHELL_H
#define SHELL_H
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define BUF_SIZE 200
#define ARG_SIZE 10
#define MAX 1024
#define DELIM " \t\r"
extern char **environ;
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *get_line(void);
char **tokenize_line(char *line, char *delim);
int _putchar(int c);

void printprompt(char *prompt);
int builtins(char *line);
int execute(char **tokens, struct stat *st);
pid_t run(char *prog, char *line, char **tokens);

void printenv(void);
char *getpath(char *name);
char *_getenv(const char *name);

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strfind(char c, char *s);

int _atoi(char *s);
#endif
