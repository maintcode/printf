#include <unistd.h>
#include <stdarg.h>
#include"main.h"
#define BUFFER_SIZE 1024
/**
 * initBop - Initializes
 * Description: the BufferedOutput structure
 * @output: content to be initialized
 * Return: void
 */
void initBop(Bop *output)
{
i	output->index = 0;
}
