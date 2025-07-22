#include "main.h"

/**
 * 
 * 
 * 
 * 
 */
void print_c(va_list args)
	{
		char c;
		c = (char) va_arg(args, int);
		write(1, &c, 1);
	}

void print_s(va_list args)
	{
		int i = 0;
		char *s;
		s = va_arg(args, char *);
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}

int _printf(const char *format, ...)
{
	int i = 0;

	type_t types[] = {
		{'c', print_c},
		{'s', print_s},
		{0, NULL}
	};
	va_list args;
	va_start (args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			char c = '%';
			if (format[i + 1] == '%')
				write(1, &c, 1);
			else
			{
				int j = 0;
				while (types[j].letter != 0)
				{
					if (format[i + 1] == types[j].letter)
					{
						types[j].p(args);
						i++;
						break;
					}
					else if (types[j].letter == 0)
					{
						write(1, "Error", 5);
					}
					j++;
				}
				
			}
		}
		else
		{
			write(1, &format[i], 1);
		}
		i++;
	}
	return(i);
}