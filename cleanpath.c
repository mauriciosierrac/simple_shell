#include "holberton.h"

/**
 * cleanpath - make a copy from de PATH and verify if start with ':'
 * @pathenv: enviroment variable PATH.
 * Return: a string with the final copy of PATH.
 */

char *cleanpath(char *pathenv)
{
	int i, j = 0;
	char *clnpath;

	if (pathenv == NULL)
		return (NULL);
	/* 5 - 1 (PATH= - .) = 4*/
	clnpath = malloc(sizeof(char) * _strlen(pathenv) - 4);

	if (pathenv[5] == ':')
		clnpath[j++] = '.';

	for (i = 5; pathenv[i]; j++, i++)
	{
		clnpath[j] = pathenv[i];
	}
	clnpath[j] = '\0';
	return (clnpath);
}
