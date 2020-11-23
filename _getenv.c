#include "holberton.h"

/**
 * _getenv - get a enviroment variable if match.
 * @name: name of the enviroment variable.
 * Return: enviroment variable, or Null if fail.
 */

char *_getenv(char *name)
{
	int i, len = 0;

	while (name[len])
		len++;

	for (i = 0; environ[i]; i++)
	{
		if (my_strcmp(environ[i], name, len) == 0)
			return (environ[i]);
	}
	return (NULL);
}
