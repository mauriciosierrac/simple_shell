#include "holberton.h"

/**
 * _execve - execute.
 * @ag: commands.
 * @hist: historial of commands.
 * @str: line.
 * Return: Status
 */

void _execve(char **ag, int hist, char *str)
{
	pid_t child_pid;
	int status, i = 0;

	child_pid = fork();

	if (child_pid == 0)
		if (execve(ag[0], ag, environ) == -1)
		{
			chk_error(ag[0], hist);
			free(str);
			while (ag[i])
			{
				free(ag[i]);
				i++;
			}
			free(ag);
			exit(state);
		}
	if (child_pid > 0)
	{
		wait(&status);
		if (WIFEXITED(status))
			state = WEXITSTATUS(status);
	}
	else
	{
		perror("Error child");
		state = EXIT_FAILURE;
	}
}
