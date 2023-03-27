#include "main.h"

/**
 * write_char - function that prints a single character
 * @c: character to print
 *
 * Return: always 1
 */
int write_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - prints a character to standard output
 * @args: optional argument passed
 *
 * Return: 1
 */
int print_char(va_list args)
{
	write_char(va_arg(args, int));
	return (1);
}

/**
 * print_string - prints a formatted string to standard output
 * @args: optional argument passed
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str;
	int i;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		write_char(str[i]);
	}
	return (i);
}

/**
 * print_percent - prints the character '%' to standard output
 * @args: optional argument passed
 *
 * Return: 1
 */
int print_percent(va_list args)
{
	write_char('%');
	return (1);
}

