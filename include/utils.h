#ifndef UTILS_H
#define UTILS_H

char *lsh_read_line(void);
char **lsh_split_line(char *line);
int lsh_launch(char **args);

#endif
