#include "main.h"

/**
 * printf_HEX - prints an hexgecimal number.
 *
 * @list: arguments.
 *
 * Return: counter.
 */

int printf_HEX(va_list list)
{
	int i;
	int *arr;
	int count = 0;
	unsigned int n = va_arg(list, unsigned int);
	unsigned int temp = n;

	while (n / 16 != 0)
	{
		n /= 16;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		arr[i] = temp % 16;
		temp /= 16;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			arr[i] = arr[i] + 7;
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}
