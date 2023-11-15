#include <unistd.h>
#include <stdarg.h>
#include"main.h"
#define BUFFER_SIZE 1024
/**
 * writeCharToBuffer -  Writes a character
 * Description: to the buffered output
 * @c: character to be written
 * @output: count to be
 * Return: void
 */
void writeCharToBuffer(Bop *output, char c)
{
	if (output->index < BUFFER_SIZE - 1)
	{
		output->buffer[output->index++] = c;
	}
	else
	{
		flushBop(output);  /* flushed if the buffer is full */
		output->buffer[output->index++] = c;
	}
}
