#include "holberton.h"

void write_buf(char **buf, char *str)
{
	char *token;
	char delim[] = " \n";
	int i = 0;

	token = strtok(str, delim);

	while (token)
	{
		buf[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
}
