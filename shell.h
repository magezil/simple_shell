#ifndef SHELL_H
#define SHELL_H
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
extern char **environ;
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *get_line(void);
char **tokenize_line(char *line);
void non_interactive_mode(void);
int _strcmp(char *s1, char *s2);
int _putchar(int c);
void printenv(void);
char *getpath(char *name);
char *_getenv(const char *name);
char *_strcpy(char *dest, char *src);
#endif
