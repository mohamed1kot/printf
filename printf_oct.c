#include "main.h"

/**
 * printf_oct - prints an octal number.
 *
 * @list: arguments.
 *
 * Return: counter.
 */

int printf_oct(va_list list)
{
	int i;
	int *arr;
	int count = 0;
	unsigned int num = va_arg(list, unsigned int);
	unsigned int temp = num;

	while (num / 8 != 0)
	{
		num /= 8;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		arr[i] = temp % 8;
		temp /= 8;
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}
