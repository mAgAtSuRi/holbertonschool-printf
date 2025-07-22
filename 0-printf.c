#include "main.h"
/**
 * print_c - prints a character
 * @va_list: list of arguments
 */
void print_c(va_list args)
{
	char c;

	c = (char) va_arg(args, int);
	write(1, &c, 1);
}

/**
 * print_s - prints a string
 * @va_list: list of arguments
 */
void print_s(va_list args)
{
	char *s;
	int i = 0;

	s = va_arg(args, char *);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
/**
 * _printf - Prints a string that can handle char/string variable
 * @format: the string to print
 *
 * Return: the number of characters in the string
 */
int _printf(const char *format, ...)
{
	int i = 0; int j;
	char percentage = '%';
	type_t types[] = {
	{'c', print_c},
	{'s', print_s},
	{0, NULL}
	};
	va_list args;

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				write(1, &percentage, 1);
			else
			{
				j = 0;
				while (types[j].letter != 0)
				{
					if (format[i + 1] == types[j].letter)
					{
						types[j].p(args);
						i++;
						break;
					}
					else if (types[j].letter == 0)
						write(1, "error", 5);
					j++;
				}
			}
		}
		else
			write(1, &format[i], 1);
		i++;
	}

	return (i);
}
