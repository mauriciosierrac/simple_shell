#include "holberton.h"

/**
 * main - Start our own shell
 * Return: something.
 */

int main()
{
	char *c = "$ ", *str = NULL, **array;
	int command, i, status = 0;
	size_t n = 0;
	struct stat st;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, c, 2);

		command = getline(&str, &n, stdin);

		if (command == EOF)
		{
			if (isatty(STDIN_FILENO))
				_putchar(10);
			our_exit(str, status);
		}

		if (command != -1)
		{
			if (chk_builtin(str, status) == 0)
			{
				array = chk_path(str);
				status = stat(array[0], &st);
				if (status == 0)
					_execve(array);
				else
					perror("./hsh");
				for (i = 0; array[i]; i++)
					free(array[i]);
				free(array);
			}
		}
		else
				perror("./hsh");
	}
	free(str);
	return (0);
}
