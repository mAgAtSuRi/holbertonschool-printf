#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

int _printf(const char *format, ...);

typedef struct type
{
	char letter;
	int (*p)(va_list);
} type_t;
int print_c(va_list);
int print_s(va_list);
int print_num(va_list);

#endif