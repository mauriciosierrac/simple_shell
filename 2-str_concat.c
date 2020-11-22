#include <stdlib.h>

/**
* str_concat - concatenate 2 str
* @s1: string 1
* @s2: string 2
* Return: Null if size 0
*/

char *str_concat(char *s1, char *s2)
{
	unsigned int i, j, l, l1 = 0, l2 = 0;
	char *p;

	/* primero asigno el tamaño de memoria con Malloc */

	if (s1 != NULL)
	{
		while (s1[l1] != 0)
			l1++;
	}
	if (s2 != NULL)
	{
		while (s2[l2] != 0)
		l2++;
	}

	l = l1 + l2 + 2;

	p = malloc(sizeof(char) * l);

	if (p == NULL)
		return (NULL);

	for (i = 0; i < l1; i++)
		p[i] = s1[i];
	p[i++] = '/';
	for (j = 0; j < l2; j++)
		p[i + j] = s2[j];
	p[i + j] = 0;

	return (p);
}
