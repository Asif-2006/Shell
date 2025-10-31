#include "shell.h"

char *builtin_str[] = {"cd", "help", "exit", "greet", "clear", "about"};

int (*builtin_func[])(char **) = {
    &lsh_cd, &lsh_help, &lsh_exit, &lsh_greet, &lsh_clear, &lsh_about
};

int lsh_num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

int lsh_cd(char **args) {
    if (args[1] == NULL)
        fprintf(stderr, "lsh: expected argument to \"cd\"\n");
    else if (chdir(args[1]) != 0)
        perror("lsh");
    return 1;
}

int lsh_help(char **args) {
    printf("MiniShell Commands:\n");
    for (int i = 0; i < lsh_num_builtins(); i++)
        printf("  %s\n", builtin_str[i]);
    return 1;
}

int lsh_greet(char **args) {
    printf("Hello, %s! 👋\n", args[1] ? args[1] : "Asif");
    return 1;
}

int lsh_clear(char **args) {
    printf("\033[H\033[J");
    return 1;
}

int lsh_about(char **args) {
    printf("Asif’s Custom Shell v1.0 — built with C and WSL\n");
    return 1;
}

int lsh_exit(char **args) { return 0; }
