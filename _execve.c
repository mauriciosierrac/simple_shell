#include "holberton.h"


void _execve(char **ag)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == 0)
		execve(ag[0], ag, environ);
	if (child_pid > 0)
		wait(&status);
	else
		perror("Error: ");
}
