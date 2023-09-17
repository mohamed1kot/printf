#include "main.h"

/**
 * print_string - Prints a string.
 *
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier.
 *
 * Return: Number of chars printed
 */

int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int len = 0, i;
	char *ptr = va_arg(types, char *);

	(void)(buffer);
	(void)(flags);
	(void)(width);
	(void)(size);
	if (ptr == NULL)
	{
		ptr = "(null)";
		if (precision >= 6)
			ptr = "      ";
	}

	while (ptr[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &ptr[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &ptr[0], len);
			return (width);
		}
	}

	return (write(1, ptr, len));
}

/**
 * print_percent - Prints a percent sign.
 *
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier.
 *
 * Return: Number of chars printed
 */

int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	(void)(types);
	(void)(buffer);
	(void)(flags);
	(void)(width);
	(void)(precision);
	(void)(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_neg, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints an unsigned number.
 *
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier.
 *
 * Return: Numbers of char printed.
 */

int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n, m, i, s;
	unsigned int a[32];
	int c;

	(void)(buffer);
	(void)(flags);
	(void)(width);
	(void)(precision);
	(void)(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, s = 0, c = 0; i < 32; i++)
	{
		s += a[i];
		if (s || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			c++;
		}
	}
	return (c);
}

/**
 * get_flags - Calculates active flags.
 *
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 *
 * Return: Flags:
 */

int get_flags(const char *format, int *i)
{
	int j, curr_i;
	int flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CH[j])
			{
				flag |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flag);
}
