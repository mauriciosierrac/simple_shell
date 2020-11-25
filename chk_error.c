#include "holberton.h"

/**
 * error_no_such - error when no such file or directory
 * @str: string.
 * @hist: historial of commands
 */

void error_no_such(char *str, int hist)
{
	char *ps = ": ";
	char *nf = "not found\n";

	_puts(sh_call);
	_puts(ps);
	int_to_str(hist);
	_puts(ps);
	_puts(str);
	_puts(ps);
	_puts(nf);
	state = 127;
}

/**
 * error_permission - error when permissions denied.
 * @str: string.
 * @hist: historial of commands
 */

void error_permission(char *str, int hist)
{
	char *ps = ": ";
	char *pd = "Permission denied\n";

	_puts(sh_call);
	_puts(ps);
	int_to_str(hist);
	_puts(ps);
	_puts(str);
	_puts(ps);
	_puts(pd);
	state = 126;
}

/**
 * chk_error - check error.
 * @str: string.
 * @hist: historial of commands
 */
void chk_error(char *str, int hist)
{
	int i;

	i = _strlen(str);
	str[i] = '\0';

	if (errno == ENOENT)
		error_no_such(str, hist);
	else if (errno == EACCES)
		error_permission(str, hist);
	else
		state = 2;
}
