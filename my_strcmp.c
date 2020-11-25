#include "holberton.h"
/**
 * chk_void - chekck if the string is void.
 * @env: string 1.
 * Return: -1 if the strings are diferents, in the other case, 0.
 */

int chk_void(char *env)
{
	int j = 0;

	if (env[0] == ' ')
		while (env[j] == ' ')
			j++;
	if (env[j] == '\n' && env[j + 1] == '\0')
		return (0);
	return (-1);
}

/**
 * my_strcmp - compare two strings.
 * @env: string 1.
 * @str: string 2.
 * @len: chars to compare.
 * Return: -1 if the strings are diferents, in the other case, 0.
 */

int my_strcmp(char *env, const char *str, int len)
{
	int j;

	for (j = 0; j < len; j++)
	{
		if (env[j] != str[j])
			return (-1);
	}

	return (0);
}
