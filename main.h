#ifndef MAIN_H
#define MAIN_H

/*libraries and headers*/
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

/*extern variables*/
extern char **environ;

/**Prototypes*/

int _putchar(char c);
int count_digits(int num);
char *num_to_string(int num);
int print_err_num(char **num, char *command);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strcpy(char *dest, const char *src);
char _strncpy(char *dest, const char *src, int n);
int _getchar(void);
int _puts(char *str);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int isDelim(char c, const char *delim);
char *_strtok(char *str, const char *delim);
void *_realloc(void *old_ptr, size_t old_size, size_t new_size);
int _getline(char **lineptr, size_t *n, FILE *stream);
void print_env(void);
char *get_command_path(char *command, int *code);
int exec_command(char **argv, size_t commandCount);
void free_argv_set_to_NULL(char ***argv);
void aloc_argv(char ***argv, size_t n, char **token, const char *d, char **lc);
void free_str_dup_set_null(char **str);
#endif /*MAIN_H*/

