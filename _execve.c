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
		execve(ag[0], ag, environ);
	if (child_pid > 0)
		wait(&status);
	else
		chk_error(ag[0], hist);
}
