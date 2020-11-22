#include "holberton.h"

/**
 *
 *
 *
 */

int our_exit(char *str)
{
	free(str);
	exit(EXIT_SUCCESS);
}

/**
 *
 *
 *
 */

int _printenv(char *str)
{
	int i, j;

	if (!str)
		return (0);

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
		{
			if (environ[i][j] == ':')
				_putchar(10);
			else
				_putchar(environ[i][j]);
		}
	}
	return (1);
}
