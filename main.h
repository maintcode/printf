#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>
#define BUFFER_SIZE 1024

/* Structure to represent the buffered output */
/**
 * struct BufferedOutput - structure
 * Description: to hold the buffer and the current index
 * BUFFER_SIZE: size of the buffer
 * @buffer: member of the struct
 * @index: member of the struct
 * Return:(0)
 */
typedef struct BufferedOutput
{
	char buffer[BUFFER_SIZE];
	size_t index;  /*current index in the buffer */
} Bop;

void initBop(Bop *output);
{
	output->index = 0;

}
void flushBop(Bop *output);
void writeCharToBuffer(Bop *output, char c);
void writeStringToBuffer(Bop *output, const char *str);
void bufferedPrintf(const char *format, ...);

int _putchar(char c);
int _puts(char *str);
int is_digit(char c);
void reverse_array(int *a, int n);
int _printf(const char *format, ...);
char *rot13(char *str);

int printrR(const char *format, ...);
int print_longshort(const char *format, ...);
int print_binary(const char *format, ...);

#endif
