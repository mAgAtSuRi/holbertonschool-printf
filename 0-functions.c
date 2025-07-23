#include "main.h"

/**
 * print_c - prints a character
 * @va_list: list of arguments
 */
int print_c(va_list args)
{
	char c;

	c = (char) va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

/**
 * print_s - prints a string
 * @va_list: list of arguments
 */
int print_s(va_list args)
{
	char *s;
	int i = 0;

	s = va_arg(args, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

/**
 * print_num - print numbers
 * @va_list: list of arguments
 */
int print_num(va_list args)
{
	char tab[12];
	char reverse_tab[12];
	long int d, i, count_num = 0, num_negative = 0;

	d = va_arg(args, long int);

	if (d == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (d < 0)
	{
		write(1, "-", 1);
		if (d == INT_MIN)
			d = INT_MAX;
		else
			d = -d;
		num_negative++;
	}

	for (i = 0; d > 0; i++)
	{
		reverse_tab[i] = d % 10 + '0';
		if (d > 0)
			count_num++;
		d = d / 10;
	}	

	if (count_num == 0)
		return (0);
	for (i = count_num - 1; i >= 0; i--)
	{
		tab[count_num - 1 - i] = reverse_tab[i];
		write(1, &tab[count_num - 1 - i], 1);
	}
	return (count_num + num_negative);
}
