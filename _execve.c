#include "holberton.h"

/**
 * _execve - execute.
 * @ag: commands.
 * @hist: historial of commands.
 * Return: Status
 */

void _execve(char **ag, int hist)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(ag[0], ag, environ) == -1)
		{
			chk_error(ag[0], hist);
			exit(state);
		}
	}
	if (child_pid > 0)
	{
		wait(&status);

		if (WIFEXITED(status))
			state = WEXITSTATUS(status);
	}
	else
		chk_error(ag[0], hist);
}
