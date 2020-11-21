#include "holberton.h"

char *chk_path(char *str)
{
	int l1, l2, i;
	char *envpath = "PATH";
	char *concat = NULL, *pget = NULL;
	char **pbuf;
	struct stat st;

	pget = _strdup(_getenv(envpath));
	if (pget)
	{
		pbuf = write_buf(pget, ":");
		for (i = 0; pbuf[i]; i++)
		{
			l1 = 0, l2 = 0;
			concat = malloc(sizeof(char) * (strlen(pbuf[i]) + strlen(str)));
			while ((pbuf[i])[l1])
			{
				concat[l1] = (pbuf[i])[l1];
				l1++;
			}
			concat[l1++] = '/';
			while (str[l2])
			{
			concat[l2 + l1] = str[l2];
				l2++;
			}
			if (stat(concat, &st) == 0)
			{
				for (i = 0; pbuf[i]; i++)
					free(pbuf[i]);
				free(pbuf);
				free(pget);
				return (concat);
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
