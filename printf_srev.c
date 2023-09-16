#include "main.h"

/**
 * printf_srev - function that prints a str in reverse.
 *
 * @list: type struct va_arg where is allocated printf arguments.
 *
 * Return: the counter.
 */

int printf_srev(va_list list)
{

	char *ptr = va_arg(list, char*);
	int i;
	int j = 0;

	if (ptr == NULL)
		ptr = "(null)";
	while (ptr[j] != '\0')
		j++;
	for (i = j - 1; i >= 0; i--)
		_putchar(ptr[i]);
	return (j);
}
