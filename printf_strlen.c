#include "main.h"

/**
 * _strlen - Returns the lenght of a string.
 *
 * @c: Type char pointer
 *
 * Return: s.
 */

int _strlen(char *c)
{
	int s;

	for (s = 0; c[s] != 0; s++)
		;
	return (s);

}
