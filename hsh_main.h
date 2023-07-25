#ifndef _HSH_MAIN_H
#define _HSH_MAIN_H
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
extern char **environ;

void _handle_signal(int signal);
int *_error(char *argv, int count, char *args);

int func_exit(char **args);
void _printenv(char **env);

char **_which(char *foundpath);
char *_getenv(char *name, char **env);
char *search_func(char **dir, char *cmd);
int _child_process(char **av, char **args, char **environ, int st, int countt);
int _access(char *filename);

char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strstr(char *str1, char *str2);
char *_strdup(char *str);
char *_itoa(int num, int base);

char *_read_input(void);
char **_sep_str(char *line, char **env);
int execute(char **args, char **argv, int count, char *line, char **env);
void prompt(void);

void *_realloc(void *ptr, unsigned int new_size);
int _count_point(char *buffer);

void *_calloc(unsigned int nmemb, unsigned int size);
char **_search_path(char **environ);
int _stat(char **cmd, char **path);
char *str_concat(char *s1, char *s2);
void _puts(char *str);
int _putchar(char c);

#endif
