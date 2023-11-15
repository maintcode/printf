#include"main.h"
/**
 * precision_non_custom - Handle the precision
 * Description:for non-custom conversion specifiers
 * @format: the format string
 * @i: paramenter to be printed
 * Return: precision
 */
int precision_non_custom(const char *format, int *i, ...)
{
	unsigned int index = *i + 1, precision = -1;
	va_list arg;

	va_start(arg, i);
	for (index += 1; format[index] != '\0'; index++)
	{
		if (format[index] != '.')
			return (precision);
		precision = 0;
		if (is_digit(format[index]))
		{
			precision *= 10;
			precision += format[index] - '0';
		}
		else if (format[index] == '*')
		{
			index++;
			precision = va_arg(arg, int);
			break;
		}
		else
			break;
		*i = index - 1;
	}
	va_end(arg);
	return (precision);
}
