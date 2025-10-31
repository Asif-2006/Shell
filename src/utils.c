#include "shell.h"

char *lsh_read_line(void) {
    int bufsize = 1024, position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer) { fprintf(stderr, "allocation error\n"); exit(EXIT_FAILURE); }

    while (1) {
        c = getchar();
        if (c == EOF || c == '\n') { buffer[position] = '\0'; return buffer; }
        else buffer[position++] = c;

        if (position >= bufsize) {
            bufsize += 1024;
            buffer = realloc(buffer, bufsize);
            if (!buffer) { fprintf(stderr, "allocation error\n"); exit(EXIT_FAILURE); }
        }
    }
}

char **lsh_split_line(char *line) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(sizeof(char *) * bufsize);
    char *token;

    if (!tokens) { fprintf(stderr, "allocation error\n"); exit(EXIT_FAILURE); }

    token = strtok(line, " \t\r\n\a");
    while (token != NULL) {
        tokens[position++] = token;
        if (position >= bufsize)
            tokens = realloc(tokens, sizeof(char *) * (bufsize += 64));
        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return tokens;
}
