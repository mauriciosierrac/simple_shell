#include "holberton.h"

/**
 * main - Start our own shell
 * Return: something.
 */

int main(void)
{
	char *c = "$ ", *str = NULL, **array;
	int command, i;
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
			our_exit(str);
		}

		if (command != -1)
		{
			if (chk_builtin(str) == 0)
			{
				array = chk_path(str);

				if (stat(array[0], &st) == 0)
					_execve(array);
				else
					perror("./hsh");
				for (i = 0; array[i]; i++)
					free(array[i]);
				free(array);
			}
		}
		else
			if (isatty(STDIN_FILENO))
				perror("./hsh");
	}
	free(str);
	return (0);
}
