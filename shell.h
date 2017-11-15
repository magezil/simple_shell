#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define BUF_SIZE 200
#define ARG_SIZE 10
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *get_line(void);
char **tokenize_line(char *line);
#endif
