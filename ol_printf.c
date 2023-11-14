#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...);
int handle_format(va_list args, char specifier);
int write_char(va_list args);
int write_str(va_list args);
int write_str_reverse(char *str);

/**
 * _printf - Produces output according to a format
 * Description: Implementation of printf
 * @format: Format specifier
 * Return: The number of characters printed (excluding the null byte used
 * to end output to strings).
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
			count += handle_format(args, *++format);
		else

			count += write_char(*format);
		format++;
	}

	va_end(args);
	return (count);
}
/**
 * handle_format - Handles the convertion specifiers in the format string
 * @args: The variable arguments list.
 * @specifier: The conversion specifier character.
 * Description: Implementation to handle format
 * Return: The number of characters handled
 */

int handle_format(va_list args, char specifier)
{
	if (specifier == 'c')
		return (write_char(va_arg(args, int)));

	if (specifier == 's')
		return (write_str(va_arg(args, char *)));

	if (specifier == 'r')
		return (write_str_reverse(va_arg(args, char *)));


	return (0);
}

/**
 * write_char - Writes a character to the standard output
 * @c: The character to write.
 * Description: Implementation of write_char
 * Return: The number of characters written
 */

int write_char(va_list args)
{
	putchar(c);
	return (1);
}

/**
 * write_str - Writes a string to the standard output.
 * @str: The string to write
 * Descritption: Implementation of write_str
 * Return: The number of characters written.
 */

int write_str(char *str)
{
	int count = 0;

	while (*str)
	{
		putchar(*str);
		str++;
		count++;
	}

	return (count);
}
/**
 * write_str_reverse - Writes a string in reverse to the standard output
 * @str: The string to write in reverse
 * Description: Implemetation of write_str_reverse
 * Return: The number of character written
 */
int write_str_reverse(char *str)
{
	int count = 0;
	int len = 0;


	while (str[len])
		len++;


	for (i = len - 1; i >= 0; i--)
	{
		putchar(str[i]);
		count++;
	}

	return (count);
}
