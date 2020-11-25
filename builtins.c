#include "holberton.h"

/**
 * our_exit - exit
 * @str: string from getline.
 * Return: Exit Success.
 */

int our_exit(char *str)
{
	free(str);
	exit(EXIT_FAILURE);
}

/**
 * _printenv - print env
 * @str: string from getline.
 * Return: 1 on success, 0 if fail.
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
			_putchar(environ[i][j]);
		}
		_putchar(10);
	}
	return (1);
}
