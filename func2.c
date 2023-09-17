#include "main.h"

/**
 * print_pointer - Pints the value of a pointer variable.
 *
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier.
 *
 * Return: Number of chars printed.
 */

int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char ex_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, len = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	(void)(width);
	(void)(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	(void)(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		ex_c = '+', len++;
	else if (flags & F_SPACE)
		ex_c = ' ', len++;

	ind++;
	return (write_pointer(buffer, ind, len,
				width, flags, padd, ex_c, padd_start));
}

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 *
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier.
 *
 * Return: Number of chars printed
 */

int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0, off_set = 0;
	char *str = va_arg(types, char *);

	(void)(flags);
	(void)(width);
	(void)(precision);
	(void)(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + off_set] = str[i];
		else
			off_set += append_hexa_code(str[i], buffer, i + off_set);

		i++;
	}

	buffer[i + off_set] = '\0';

	return (write(1, buffer, i + off_set));
}

/**
 * print_reverse - Prints reverse string.
 *
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier.
 *
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *ptr;
	int i, c = 0;

	(void)(buffer);
	(void)(flags);
	(void)(width);
	(void)(size);

	ptr = va_arg(types, char *);

	if (ptr == NULL)
	{
		(void)(precision);

		ptr = ")Null(";
	}
	for (i = 0; ptr[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = ptr[i];

		write(1, &z, 1);
		c++;
	}
	return (c);
}

/**
 * print_rot13string - Print a string in rot13.
 *
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier.
 *
 * Return: Numbers of chars printed
 */

int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	char *ptr;
	unsigned int i, j;
	int c = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	ptr = va_arg(types, char *);
	(void)(buffer);
	(void)(flags);
	(void)(width);
	(void)(precision);
	(void)(size);

	if (ptr == NULL)
		ptr = "(AHYY)";
	for (i = 0; ptr[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == ptr[i])
			{
				x = out[j];
				write(1, &x, 1);
				c++;
				break;
			}
		}
		if (!in[j])
		{
			x = ptr[i];
			write(1, &x, 1);
			c++;
		}
	}
	return (c);
}

/**
 * print_char - Prints a char.
 *
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier.
 *
 * Return: Number of chars printed
 */

int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char ch = va_arg(types, int);

	return (handle_write_char(ch, buffer, flags, width, precision, size));
}
