#include <unistd.h>
#include <stdarg.h>
#define BUFFER_SIZE 1024
#include"main.h"
/**
 * bufferedPrintf - Printf-like function
 * Description: that uses buffered output
 * @format: format specifier
 * Return: void
 */
void bufferedPrintf(const char *format, ...)
{
	va_list args;
	Bop output;

	va_start(args, format);

	initBop(&output);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;  /* move past the '%' */
			if (*format == 's')
			{
				const char *str = va_arg(args, const char *);

				writeStringToBuffer(&output, str);
			}
			else if (*format == 'c')
			{
				char c = (char)va_arg(args, int);  /* char is promoted to int in va_arg */

				writeCharToBuffer(&output, c);
			}
			else /* Other format specifiers and Ordinary character to be handle */
				writeCharToBuffer(&output, *format);
			format++; /* move to the next character in the format string */
		}
	}
	flushBop(&output);  /* flush any remaining content in the buffer */
	va_end(args);
}






