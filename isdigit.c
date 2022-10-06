#include "monty.h"

/**
 * _isdigit - checks for a digit (0 through 9)..
 * @c: value to check
 * Return:Returns 1 when c is a digit and 0 otherwise
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
