#include "holberton.h"

/**
*
*
*/

int main()
{
	char *c = "$ ", *str = NULL;
	int command, i;
	size_t n = 0;
	struct stat st;
	char **array;

	while (1)
	{
		write (STDOUT_FILENO, c, 2);
		command = getline(&str, &n, stdin);

		if (command == EOF)
			break;

		if (command != -1)
		{
			if (chk_builtin(str) == 0)
			{
				array = chk_path(str);

				if (stat(array[0], &st) == 0)
					_execve(array);
				else
					perror("ErrorMain: ");
				for (i = 0; array[i]; i++)
					free(array[i]);
				free(array);
			}
		}
		else
			perror("Error");
	}
	free(str);
	return(0);
}
