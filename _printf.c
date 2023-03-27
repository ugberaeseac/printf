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

	datatype select[] = {{'c', print_char},
			{'s', print_string},
			{'%', print_percent},
			{'\0', NULL}};
	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; select[j].list != '\0'; j++)
			{
				if (select[j].list == format[i + 1])
				{
					ret += select[j].fptr(args);
					i++;
					break;
				}
			}
			if (select[j].list == '\0' && format[i + 1] != '\0')
			{
				write_char(format[i]);
				ret++;
			}
		}
		else
		{
			write_char(format[i]);
			ret++;
		}
	}
	va_end(args);
	return (ret);
}
