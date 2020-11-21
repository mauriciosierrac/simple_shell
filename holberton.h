#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

/**
 * struct list_s - lista enlazada individualmente
 * @str: string - (cadena malloc'ed)
 * @next: apunta al siguiente nodo
 */

typedef  struct list_s
{
	char * str;
	struct list_s * siguiente;
} list_t ;

extern char **environ;

/* PROTOTYPES */

void _execve(char **ag);
char **write_buf(char *, char *);
char *chk_path(char *);
int my_strcmp(char *env, const char *str, int len);
char *_getenv(char *);
char *_strdup(char *str);

#endif /*HOLBERTON*/
