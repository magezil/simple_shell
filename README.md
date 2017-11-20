# Simple_shell

Write a simple `UNIX` command interpreter in C

## Compilation

`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

## Usage

### Interactive mode
`$ ./hsh
hsh$ /bin/ls
hsh main.c shell.c
hsh$
hsh$ exit
$ `

### Non-interactive mode
`$ echo "/bin/ls" | ./hsh
hsh main.c shell.c
$`

## Files

### README.md
README file for simple shell

### man_1_simple_shell
man page for simple shell

### AUTHORS
Contributing authors for this project

### shell.h
Header file for simple shell program

### shell.c
Program that runs simple shell

Other files included contain helper functions for the simple shell

## `/tests`
Folder contains all tests
