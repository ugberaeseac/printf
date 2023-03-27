#include "main.h"

/**
* _printf - writes formatted string to standard output
* @format: formatted string to print
* Return: number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int i, j;
	int ret = 0;

	datatype select[] = {
			{'c', print_char},
			{'s', print_string},
			{'%', print_percent},
			{'\0', NULL}
			};
	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		/*DO SOMETHING!*/
	}
}
