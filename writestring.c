#include <unistd.h>
#include <stdarg.h>
#include"main.h"
#define BUFFER_SIZE 1024
/**
 * writeStringToBuffer - Writes a formatted string
 * Description: to the buffered output
 * @str: string to be written out
 * @output: count to be
 * Return: void
 */
void writeStringToBuffer(Bop *output, const char *str)
{
	while (*str != '\0')
	{
		writeCharToBuffer(output, *str++);
	}
}
