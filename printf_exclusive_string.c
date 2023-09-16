#include "main.h"

/**
 * printf_exclusive_string - print exclusuives string.
 *
 * @list: arguments.
 *
 * Return: the length of the string.
 */

int printf_exclusive_string(va_list list)
{
	char *ptr;
	int i, len = 0;
	int cast;

	ptr = va_arg(list, char *);
	if (ptr == NULL)
		ptr = "(null)";
	for (i = 0; ptr[i] != '\0'; i++)
	{
		if (ptr[i] < 32 || ptr[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = len + 2;
			cast = ptr[i];
			if (cast < 16)
			{
				_putchar('0');
				len++;
			}
			len = len + printf_HEX_aux(cast);
		}
		else
		{
			_putchar(ptr[i]);
			len++;
		}
	}
	return (len);
}
