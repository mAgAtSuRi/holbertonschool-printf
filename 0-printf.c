#include "main.h"

/**
 * check_known - prints % and character after if the command is not valid
 * @n: always = 0 if the command is not valid
 * @c0: first character to print (%)
 * @c1: character after the % to print
 * @i: position counter of the string to print
 * @charnum: number of character to print
 */
void check_known(int n, char c0, char c1, int *i, int *charnum)
{
	if (n == 0)
	{
		write(1, &c0, 1);
		write(1, &c1, 1);
		*i += 2;
		*charnum += 2;
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
	int i = 0, j, char_known, char_num = 0;
	char percentage = '%';
	type_t types[] = {
	{'c', print_c},
	{'s', print_s},
	{'d', print_num},
	{'i', print_num},
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
			{write(1, &percentage, 1);
				i += 2;
				char_num++; }
			else
			{j = 0;
				while (types[j].letter != 0)
				{
					if (format[i + 1] == types[j].letter)
					{char_num += types[j].p(args);
						i += 2;
						char_known = 1;
						break; }
					j++; }
				check_known(char_known, format[i], format[i + 1], &i, &char_num); }
		}
		else
		{write(1, &format[i], 1);
			i++;
			char_num++; } }
	return (char_num);
}
