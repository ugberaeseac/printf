#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

/**
* struct data - user-defined data type
* @list: first member of struct data
* @fptr: second member of struct data
* Description: datatype is struct data abbreviation
*/

typedef struct data
{
	char list;
	int (*fptr)(va_list);
} datatype;

int write_char(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif /* #ifndef MAIN_H */
