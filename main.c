#include "holberton.h"

/**
*
*
*
*
*/

int main()
{
	char *c = "$ ", *str = NULL;
	int command;
	size_t n = 0;
	struct stat st;
	char *array[4];

	while (1)
	{
		write (STDOUT_FILENO, c, 2);
	
		if ((command = getline(&str, &n, stdin) != -1))
		{
			write_buf(array, str);

			if(stat(array[0], &st) == 0)
			{
				_execve(array);
				clean_buf(array);
			}
			else
				perror("Error: ");
		}
	}
	free(str);
	return(0);
}
