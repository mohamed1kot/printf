#include "main.h"

/**
 * printf_unsigned - prints integer.
 *
 * @list: argument to print
 *
 * Return: number of characters printed.
 */

int printf_unsigned(va_list list)
{
	unsigned int n = va_arg(list, unsigned int);
	int num, last = n % 10, digit, e = 1;
	int  i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		num = -num;
		n = -n;
		last = -last;
		putchar('-');
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			e = e * 10;
			num = num / 10;
		}
		num = n;
		while (e > 0)
		{
			digit = num / e;
			_putchar(digit + '0');
			num = num - (digit * e);
			e = e / 10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
}
