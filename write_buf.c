#include "holberton.h"

char **write_buf(char *str, char *delim)
{
	char *token;
	char **buf;
	int i, con = 0, j = 0;

	for (i = 0; str[i]; i++)
		if(str[i] == ' ' || str[i] == '\n')
			con++;

	buf = malloc(sizeof(char *) * (con + 1));
	token = strtok(str, delim);

	while (token)
	{
		buf[j] = _strdup(token);
		token = strtok(NULL, delim);
		j++;
	}
	buf[j] = NULL;
	return (buf);
}
