#include <stdarg.h>
#include <unistd.h>
#include"main.h"
/**
 * ptr_conversion_specifier - Handle the following conversion specifier
 * Description: p which is a pointer
 * @format: the format specifier
 * Return: number of bytes printed
 */
size_t ptr_conversion_specifier(const char *format, ...)
{
	size_t count = 0;
	unsigned int index, strcount, addresscount = 0;
	char map_to[] = "0123456789abcdef";
	va_list arg;
	
	va_start(arg, format);
	for (index = 0; format[index] != '\0'; index++)
	{
		if (format[index] != '%')
			count += write(1, &format[index], 1);
		if (format[index] == '%' && format[index + 1] == 'p')
		{
			while (addresscount > 0)
			{
				strcount = write(1, va_arg(arg, void *), sizeof(void *));
				count += strcount;
				addresscount -= strcount;
			}
			index++;
			addresscount += write(1, va_arg(arg, void *), sizeof(void *));
		}
	}
	va_end(arg);
	return (count);

}

