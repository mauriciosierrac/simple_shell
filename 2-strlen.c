#include "holberton.h"
/**
* _strlen - size of array
* @s: string
* Return: len
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}
