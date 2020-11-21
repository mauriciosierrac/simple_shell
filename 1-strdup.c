#include <stdlib.h>

/**
* _strdup - duplicates
* @str: string to copy
* Return: Null if size 0 or if not memory available
*/

char *_strdup(char *str)
{
	unsigned int i = 0, j;
	char *p;

	if (str == NULL)
		return (NULL);
	/* primero asigno el tamaño de memoria con Malloc */

	while (str[i] != 0)
		i++;

	p = malloc(i + 1);

	if (p == NULL)
		return (NULL);

	for (j = 0; str[j] != 0; j++)
		p[j] = str[j];

	p[j] = '\0';
	return (p);
}
