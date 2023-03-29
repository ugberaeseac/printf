#include "main.h"

/**
 * print_binary - converts a number from base 10 to binary
 * @args: optional argument to convert
 *
 * Return: number of characters of converted number
 */

int print_binary(va_list args)
{
	unsigned int number;
	int i, length = 0;
	char *str;
	char *rev;

	number = va_arg(args, unsigned int);
	if (number == 0)
		return (write_char('0'));

	if (number < 1)
		return (-1);

	length = base_length(number, 2);
	str = malloc((sizeof(char) * length + 1));

	if (str == NULL)
		return (-1);

	for (i = 0; number > 0; i++)
	{
	if (number % 2 == 0)
		str[i] = '0';
	else
		str[i] = '1';
	number = number / 2;
	}
	str[i] = '\0';
	rev = malloc((sizeof(char) * length + 1));
	if (rev == NULL)
		return (-1);

	rev = reverse_string(str);
	for (i = 0; rev[i] != '\0'; i++)
		write_char(rev[i]);

	free(rev);
	free(str);
return (length);
}

/**
* print_unsigned_int - prints only unsigned datatype to standard outpet
* @args: optional argument to be printed
* Return: number of characters printed
*/
int print_unsigned_int(va_list args)
{
	unsigned int number, n;
	int divisor = 1, ret = 0;

	n = va_arg(args, unsigned int);

	if (n < 1)
		return (-1);
	if (n == 0 || n > 1)
		number = n;

	while ((number / divisor) > 9)
		divisor *= 10;

	while (divisor != 0)
	{
		ret += write_char('0' + (number / divisor));
		number = number % divisor;
		divisor = divisor / 10;
	}
	return (ret);
}


/**
 * print_reverse - function that reverses a string and print it
 * standard output
 * @args: optional argument to reverse
 *
 * Return: number of reversed character printed
 */

int print_reverse(va_list args)
{
	char *str;
	char *rev;
	int i;

	str = va_arg(args, char *);
	if (str == NULL)
		return (-1);

	rev = reverse_string(str);
	if (rev == NULL)
		return (-1);

	for (i = 0; rev[i] != '\0'; i++)
	{
		write_char(rev[i]);
	}

	free(rev);
	return (i);
}
