#include "holberton.h"


/**
 * chk_builtin - Verify built in functions
 * @word: string to compare
 * Return: 1 on success, 0 if fail
 */

int chk_builtin(char *word, int st)
{
	int i = 0;

	builtin func_built[] = {
		{"exit", our_exit},
		{"env", _printenv},
		{NULL, NULL}
	};

	/* Minus 1 by the '\n'*/
	if ((my_strcmp(word, "\n", 1)) == 0)
		return (1);

	while (func_built[i].str != NULL)
	{
		if (my_strcmp(word, func_built[i].str, _strlen(word) - 1) == 0)
		{
			func_built[i].fun(word, st);
			return (1);
		}
		i++;
	}
	return (0);
}
