#include "main.h"

/**
 * printf_dec - prints decimal
 *
 * @list: argument to print.
 *
 * Return: number of characters printed.
 */

int printf_dec(va_list list)
{
	int n = va_arg(list, int);
	int num, last = n % 10, digit;
	int  l = 1;
	int e = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		l++;
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
			l++;
		}
	}
	_putchar(last + '0');
	return (l);
}
