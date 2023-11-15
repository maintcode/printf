#include"main.h"
/**
 * width_custom- Handle the field width
 * Description: for non-custom conversion specifiers
 * @format: the format specifier
 * @i: parameter to be printed
 * Return: number of bytes printed
 */
int width_custom(const char *format, int *i, ...)
{
	unsigned int index, width = 0;
	va_list arg;

	va_start(arg, i);
	for (index = *i + 1; format[index] != '\0'; index++)
	{
		if (format[index] != '%')
			_putchar(format[index]);
		while (format[index] == '%')
		{
			if (is_digit(format[index]))
			{
				width *= 10;
				width += format[index] - '0';
			}
			else if (format[index] == '*')
			{
				index++;
				width = va_arg(arg, int);
				break;
			}
			else
				break;
		}
		*i = index - 1;
	}
	va_end(arg);
	return (width);
}
