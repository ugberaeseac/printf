#include "main.h"

/**
* _printf - writes formatted string to standard output
* @format: formatted string to print
* Return: number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int i, j, ret = 0, f_ret = 0;

	datatype select[] = {{'c', print_char}, {'s', print_string},
		{'%', print_percent}, {'d', print_integer}, {'i', print_integer},
		{'b', print_binary}, {'u', print_unsigned_int}, {'\0', NULL}};
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
					f_ret = select[j].fptr(args);
					if (f_ret == -1)
						return (-1);
					ret += f_ret;
					i++;
					break;
				}
			}
			if (select[j].list == '\0')
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
