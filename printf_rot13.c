#include "main.h"

/**
 * printf_rot13 - printf str to ROT13 place into buffer.
 *
 * @list: type struct va_arg where is allocated printf arguments.
 *
 * Return: counter
 */

int printf_rot13(va_list list)
{
	int i, j, count = 0;
	int k = 0;
	char *ptr = va_arg(list, char*);
	char main[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char rot[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (ptr == NULL)
		ptr = "(null)";
	for (i = 0; ptr[i]; i++)
	{
		k = 0;
		for (j = 0; main[j] && !k; j++)
		{
			if (ptr[i] == main[j])
			{
				_putchar(rot[j]);
				count++;
				k = 1;
			}
		}
		if (!k)
		{
			_putchar(ptr[i]);
			count++;
		}
	}
	return (count);
}
