#ifndef BUILTIN_H
#define BUILTIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char *builtin_str[];
extern int (*builtin_func[])(char **);
int lsh_num_builtins();

int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_greet(char **args);
int lsh_clear(char **args);
int lsh_about(char **args);

#endif
