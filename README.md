## 🔧 Organigramme de la fonction `_printf`

![Diagramme printf](assets/Diagramme%20printf.drawio.png)

# holbertonschool-printf

Group project to recreate the `printf` function.

## Objective

Reproduce the behavior of the standard `printf` function with support for the following conversions:

- `%c`: character  
- `%s`: string  
- `%%`: prints a `%`  
- `%d`, `%i`: signed decimal integers

## Function Prototype

int _printf(const char *format, ...);

## Compilation

$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c

## Example Usage (main.c)

#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");

    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;

    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);

    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);

	return (0);
}

## File Description

- **0-printf.c**: Handles the parsing of the format string and calls the appropriate function (`print_c`, `print_s`, etc.).
- **0-functions.c**:
  - `print_c()`: prints a character.
  - `print_s()`: prints a string, or `(null)` if the string is `NULL`.
  - `print_num()`: prints a signed integer (`%d`, `%i`), including negative numbers.
- **main.h**: Contains the function prototypes and required includes (`<stdarg.h>`, `<unistd.h>`, etc.).
- **main.c**: Used to test various functionalities of `_printf`.
`.


## Authors

- **Tristan MARTINEZ**
- **Esteban LEVY**
