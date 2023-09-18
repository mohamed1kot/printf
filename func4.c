#include "main.h"

/**
 * get_precision - Calculates the precision for printing.
 *
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)
{
	int curr = *i + 1;
	int precision = -1;

	if (format[curr] != '.')
		return (precision);

	precision = 0;

	for (curr += 1; format[curr] != '\0'; curr++)
	{
		if (is_digit(format[curr]))
		{
			precision *= 10;
			precision += format[curr] - '0';
		}
		else if (format[curr] == '*')
		{
			curr++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr - 1;

	return (precision);
}

/**
 * get_size - Calculates the size to cast the argument.
 *
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */

int get_size(const char *format, int *i)
{
	int curr = *i + 1;
	int s = 0;

	if (format[curr] == 'l')
		s = S_LONG;
	else if (format[curr] == 'h')
		s = S_SHORT;

	if (s == 0)
		*i = curr - 1;
	else
		*i = curr;

	return (s);
}

/**
 * get_width - Calculates the width for printing.
 *
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */

int get_width(const char *format, int *i, va_list list)
{
	int curr;
	int width = 0;

	for (curr = *i + 1; format[curr] != '\0'; curr++)
	{
		if (is_digit(format[curr]))
		{
			width *= 10;
			width += format[curr] - '0';
		}
		else if (format[curr] == '*')
		{
			curr++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr - 1;

	return (width);
}

/**
 * handle_print - Prints an argument based on its type.
 *
 * @f: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier.
 *
 * Return: 1 or 2;
 */

int handle_print(const char *f, int *ind, va_list list,
		char buffer[], int flags, int width, int precision, int size)
{
	int i, unknow = 0, print_chars = -1;
	f_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].f != '\0'; i++)
		if (f[*ind] == fmt_types[i].f)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].f == '\0')
	{
		if (f[*ind] == '\0')
			return (-1);
		unknow += write(1, "%%", 1);
		if (f[*ind - 1] == ' ')
			unknow += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (f[*ind] != ' ' && f[*ind] != '%')
				--(*ind);
			if (f[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow += write(1, &f[*ind], 1);
		return (unknow);
	}
	return (print_chars);
}
