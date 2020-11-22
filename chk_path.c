#include "holberton.h"

char **chk_path(char *str)
{
	int i;
	char *envpath = "PATH", *concat, *pget;
	char **pbuf, **array;
	struct stat st;

	array = write_buf(str, " \n");
	
	if (stat(array[0], &st) == 0)
		return (array);

	pget = _strdup(_getenv(envpath));

	if (pget)
	{
		pbuf = write_buf(pget, ":\n");
		for (i = 0; pbuf[i]; i++)
		{
			concat = str_concat(pbuf[i], str);

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
	return (NULL);
}
