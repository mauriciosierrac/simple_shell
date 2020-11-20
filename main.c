#include "holberton.h"

/**
*
*
*
*
*/

int main()
{
	char *c = "$ ", *str = NULL, delim[2] = "\n", *token;
	int command;
	size_t n = 0;
	struct stat st;
	char *array[] = {NULL, NULL, "/.", NULL};


	while (1)
	{
		write (STDOUT_FILENO, c, 2);
	
		if ((command = getline(&str, &n, stdin) != -1))
		{
			token = strtok(str,delim);
			if(stat(token, &st) == 0)
			{
				array [0] = token;
				_execve(array);
			}
			else
				perror("Error: ");
		}
	}

return(0);
}
