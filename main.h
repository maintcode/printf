#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int handle_format(va_list args, char specifier);
int write_char(va_list args);
int write_str(va_list args);
int write_int(va_list args);
int print_number(int num);

#endif /* MAIN_H */
