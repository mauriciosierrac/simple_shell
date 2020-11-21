#include "holberton.h"

/**
*
*
*
*
*/

int main()
{
	char *c = "$ ", *str = NULL, *chk = NULL;
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

			array = write_buf(str, " \n");
			chk = chk_path(array[0]);

			if (chk)
			{
				array[0] = chk;
				_execve(array);
				free(chk);
			}
			else if (stat(array[0], &st) == 0)
				_execve(array);
			else
				perror("ErrorMain: ");
			for (i = 0; array[i]; i++)
				free(array[i]);
			free(array);
		}
	}
	free(str);
	return(0);
}
