#include "holberton.h"

/**
 * chk_path - check if the first argument is a file inside de PATH directories
 * @str: string from getline
 * Return: A Buffer or Array (Double pointer).
 */

char **chk_path(char *str)
{
	int i;
	char *envpath = "PATH=", *concat, *pget;
	char **pbuf, **array;
	struct stat st;

	array = write_buf(str, " \n");

	if (array[0][0] == '.' && array[0][1] == '/')
		return (array);

	pget = (cleanpath(_getenv(envpath)));

	if (pget)
	{
		pbuf = write_buf(pget, ":\n");
		for (i = 0; pbuf[i]; i++)
		{
			concat = str_concat(pbuf[i], array[0]);

			if (stat(concat, &st) == 0)
			{
				for (i = 0; pbuf[i]; i++)
					free(pbuf[i]);
				free(pbuf);
				free(pget);
				free(array[0]);
				array[0] = concat;
				return (array);
			}
			free(concat);
		}
		for (i = 0; pbuf[i]; i++)
			free(pbuf[i]);
		free(pbuf);
	}
	free(pget);
	return (array);
}
