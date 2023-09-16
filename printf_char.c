#include "main.h"

/**
 * printf_char - prints a charater.
 * @ch: arguments.
 * Return: 1.
 */

int printf_char(va_list ch)
{
	char c;

	c = va_arg(ch, int);
	_putchar(c);
	return (1);
}
