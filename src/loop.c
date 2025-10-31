#include "shell.h"

void lsh_loop(void) {
    char *line;
    char **args;
    int status = 1;

    do {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        printf("\033[1;32mAsif@MiniShell:\033[1;34m%s\033[0m$ ", cwd);

        line = lsh_read_line();
        args = lsh_split_line(line);
        status = lsh_execute(args);

        free(line);
        free(args);
    } while (status);
}
