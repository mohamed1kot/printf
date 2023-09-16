#include "main.h"

/**
 * printf_bin - prints a binary number.
 * @list: arguments.
 * Return: 1.
 */

int printf_bin(va_list list)
{
	int l = 0;
	int c = 0;
	int i, a = 1, b;
	unsigned int num = va_arg(list, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((a << (31 - i)) & num);
		if (p >> (31 - i))
			l = 1;
		if (l)
		{
			b = p >> (31 - i);
			_putchar(b + 48);
			c++;
		}
	}
	if (c == 0)
	{
		c++;
		_putchar('0');
	}
	return (c);
}
