#include "holberton.h"

/**
 * count_delim - count delimiters in str
 * @str: string
 * @delim: delimiters
 * Return: Number of delimiters
 */

int count_delim(char *str, char *delim)
{
	int i, k, con = 1;

	for (i = 0; str[i]; i++)
	{
		for (k = 0; delim[k]; k++)
		{
			if (delim[k] == str[i])
				con++;
		}
	}
	return (con);
}

/**
 * write_buf - create a buffer (double pointer)
 * @str: string
 * @delim: delimiters
 * Return: Buffer
 */

char **write_buf(char *str, char *delim)
{
	char *token;
	char **buf;
	int con, j = 0;

	con = count_delim(str, delim);
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
