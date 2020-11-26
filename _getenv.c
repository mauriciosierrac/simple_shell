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

	if (environ == NULL)
		return (NULL);

	for (i = 0; environ[i]; i++)
		if ((my_strcmp(environ[i], name, len) == 0))
			if (_strlen(environ[i]) > 5)
				return (environ[i]);
	return (NULL);
}
