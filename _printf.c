#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's' ||
				       *(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			count += handle_format(args, *++format);
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			write(1, "%", 1);
			count++;
			format++;
		}
		else
		{
			write(1, format, 1);

			count++;
		}

		format++;
	}

	va_end(args);
	return (count);
}

/**
 * handle_format - Handles format specifiers
 * @args: Variable argument list
 * @specifier: Format specifier
 *
 * Return: Number of characters printed
 */
int handle_format(va_list args, char specifier)
{
	int count = 0;

	switch (specifier)
	{
	case 'c':
		count += write_char(args);
		break;
	case 's':
		count += write_str(args);
		break;
	case 'd':
	case 'i':
		count += write_int(args);
		break;
	}

	return (count);
}

/**
 * write_char - Writes a character to standard output
 * @args: Variable argument list
 *
 * Return: Number of characters printed
 */
int write_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);

	return (1);
}

/**
 * write_str - Writes a string to standard output
 * @args: Variable argument list
 *
 * Return: Number of characters printed
 */
int write_str(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}

	return (count);
}

/**
 * write_int - Writes a signed integer to standard output
 * @args: Variable argument list
 *
 * Return: Number of characters printed
 */
int write_int(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;

	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		count++;
	}

	count += print_number(num);
	return (count);
}

/**
 * print_number - Recursive function to print
 * @num: Integer to be printed
 *
 * Return: Number of characters printed
 */
int print_number(int num)
{
	int count = 0;
	char digit;

	if (num < 0)
	{
		write(1, "-", 1);
		count++;
		num = -num;
	}

	if (num / 10 != 0)
		count += print_number(num / 10);

	digit = (char)(num % 10) + '0';
	write(1, &digit, 1);

	return (count + 1);
}
