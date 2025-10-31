#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

// Function prototypes
char *lsh_read_line(void);
char **lsh_split_line(char *line);
int lsh_execute(char **args);
void lsh_loop(void);

// Include builtin and utility headers
#include "builtins.h"
#include "utils.h"

#endif
