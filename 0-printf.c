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
 * _printf - Prints a string that can handle char/string variable
 * @format: the string to print
 *
 * Return: the number of characters in the string
 */
int _printf(const char *format, ...)
{
	int i = 0, j, char_known, char_num = 0;
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
			char_known = 0;

			if (format[i + 1] == '\0')
				return (-1);
			else if (format[i + 1] == '%')
			{
				write(1, &percentage, 1);
				i += 2;
				char_num++;
			}
			else
			{
				j = 0;

				while (types[j].letter != 0)
				{
					if (format[i + 1] == types[j].letter)
					{
						char_num += types[j].p(args);
						i += 2;
						char_known = 1;
						break;
					}
					j++;
				}

				if (char_known == 0)
				{
					write(1, &format[i], 1);
					write(1, &format[i + 1], 1);
					i += 2;
					char_num += 2;
				}
			}
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			char_num++;
		}
	}

	return(char_num);
}
