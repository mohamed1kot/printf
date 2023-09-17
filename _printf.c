#include "main.h"

/**
 * _printf - Printf function
 *
 * @format: format.
 *
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int i, print = 0, print_char = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			print_char++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			print = handle_print(format, &i, args, buffer,
				flags, width, precision, size);
			if (print == -1)
				return (-1);
			print_char += print;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(args);

	return (print_char);
}
