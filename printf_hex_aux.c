#include "main.h"

/**
 * printf_hex_aux - prints an hexgecimal number.
 *
 * @n: arguments.
 *
 * Return: counter.
 */

int printf_hex_aux(unsigned long int n)
{
	long int i;
	long int *arr;
	long int count = 0;
	unsigned long int temp = n;

	while (n / 16 != 0)
	{
		n /= 16;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(long int));

	for (i = 0; i < count; i++)
	{
		arr[i] = temp % 16;
		temp /= 16;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			arr[i] = arr[i] + 39;
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}
