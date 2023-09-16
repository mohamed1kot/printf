#include "main.h"

/**
 * printf_string - print a string.
 *
 * @s: argumen t.
 *
 * Return: the length of the string.
 */

int printf_string(va_list s)
{
	char *ptr;
	int i, len;

	ptr = va_arg(s, char *);
	if (ptr == NULL)
	{
		ptr = "(null)";
		len = _strlen(ptr);
		for (i = 0; i < len; i++)
			_putchar(ptr[i]);
		return (len);
	}
	else
	{
		len = _strlen(ptr);
		for (i = 0; i < len; i++)
			_putchar(ptr[i]);
		return (len);
	}
}
