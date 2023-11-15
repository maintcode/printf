#include "main.h"
/**
 * _puts - a function that prints a string, followed by a new line, to stdout.
 * Description: printing  a string to stout
 * @str: a string to be printed
 * Return: (0)
 */
int _puts(char *str)
{
	int count = 0;

	if (*str)
	{
		for (count = 0; str[count] != '\0'; count++)
			_putchar(str[count]);
	}
	return (count);
}

