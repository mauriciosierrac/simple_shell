#include "holberton.h"

/**
 * our_exit - exit
 * @str: string from getline.
 * Return: Exit Success.
 */

int our_exit(char *str, int st)
{
	free(str);
	if (st == 0)
		exit(EXIT_SUCCESS);
	else
		exit(127);
}

/**
 * _printenv - print env
 * @str: string from getline.
 * Return: 1 on success, 0 if fail.
 */

int _printenv(char *str, int st)
{
	int i, j;

	if (st != 0)
		st = 0;
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
