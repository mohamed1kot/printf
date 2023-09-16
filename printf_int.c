#include "main.h"

/**
 * printf_int - prints integer.
 *
 * @num: argument to print.
 *
 * Return: number of characters.
 */

int printf_int(va_list num)
{
	int n = va_arg(num, int);
	int s, last = n % 10, digit, e = 1;
	int  i = 1;

	n = n / 10;
	s = n;

	if (last < 0)
	{
		_putchar('-');
		s = -s;
		n = -n;
		last = -last;
		i++;
	}
	if (s > 0)
	{
		while (s / 10 != 0)
		{
			e = e * 10;
			s = s / 10;
		}
		s = n;
		while (e > 0)
		{
			digit = s / e;
			_putchar(digit + '0');
			s = s - (digit * e);
			e = e / 10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
}
