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
	char *array[] = {NULL, NULL, "/.", NULL};

	while (1)
	{
		write (STDOUT_FILENO, c, 2);
	
		if ((command = getline(&str, &n, stdin) != -1))
		{
			str[command - 1] = '\0';

			if(stat(str, &st) == 0)
			{
				array[0] = str;
				_execve(array);
			}
			else
				perror("Error: ");
		}
	}

return(0);
}
