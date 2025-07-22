#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

int _printf(const char *,...);

typedef struct type {
	char letter;
	void (*p)(va_list);
} type_t;

#include <unistd.h>
#include <stdarg.h>

typedef struct type
{
	char letter;
	void (*p)(va_list);
} type_t;

int _printf(const char *format, ...);

#endif