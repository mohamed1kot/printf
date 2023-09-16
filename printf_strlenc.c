#include "main.h"

/**
 * _strlenc - Strlen function but applied for constant char pointer s.
 *
 * @c: Type char pointer.
 *
 * Return: s
 */

int _strlenc(const char *c)
{
	int s;

	for (s = 0; c[s] != 0; s++)
		;
	return (s);
}

