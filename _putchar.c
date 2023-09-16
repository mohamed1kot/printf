#include "main.h"

/**
 * _putchar - writes the character.
 *
 * @s: The character to print.
 *
 * Return: On success 1.
 */

int _putchar(char s)
{
	return (write(1, &s, 1));
}
