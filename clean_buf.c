#include "holberton.h"

void clean_buf(char **buf)
{
	int i;

	for (i = 0; buf[i]; i++)
		buf[i] = NULL;
}
