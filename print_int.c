#include "holberton.h"

/**
 * int_to_str - convert and print int to string
 * @i: number to print.
 */

void int_to_str(int i)
{
	int dig = 0, cpi = i, pot = 1;

	while (i > 0)
	{
		i = i / 10;
		dig++;
	}

	while (dig > 1)
	{
		pot *= 10;
		dig--;
	}
	for (; pot > 0; pot /= 10)
	{
		_puterror((cpi / (pot)) + 48);
		cpi %= pot;
	}
}
