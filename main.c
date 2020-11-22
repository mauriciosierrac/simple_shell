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

		if ((command = getline(&str, &n, stdin) != -1))
		{
			if (str[0] == '1')
				break;

			if (chk_builtin(str) == 0)
			{
				array = chk_path(str);

				if (stat(array[0], &st) == 0)
				{
					_execve(array);
					for (i = 0; array[i]; i++)
						free(array[i]);
					free(array);
				}
				else
					perror("ErrorMain: ");
			}
		}
	}
	free(str);
	return(0);
}
