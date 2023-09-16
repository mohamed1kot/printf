#include "main.h"

/**
 * printf_pointer - prints an hexgecimal number.
 *
 * @list: arguments.
 *
 * Return: counter.
 */

int printf_pointer(va_list list)
{
	void *ptr;
	char *ss = "(nil)";
	long int a;
	int b;
	int i;

	ptr = va_arg(list, void*);
	if (ptr == NULL)
	{
		for (i = 0; ss[i] != '\0'; i++)
		{
			_putchar(ss[i]);
		}
		return (i);
	}

	a = (unsigned long int)ptr;
	_putchar('0');
	_putchar('x');
	b = printf_hex_aux(a);
	return (b + 2);
}
