#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define max_buf_size 64;
void exc_cmd(char **args);
/*char *get_loc(char *cmd);*/
void tokenize(char *line, char ***args);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void free_2d(char ***args);
#endif
