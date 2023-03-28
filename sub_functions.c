#include "main.h"

/**
 * base_length - function to get the length of a number after
 * converting it to a numeric base
 * @number: number whose length is to calculated
 * @base: specific base to be used
 *
 * Return: length of the number in specific base
 */
int base_length(unsigned int number, unsigned int base)
{
	unsigned int i;

	for (i = 0; number != 0; i++)

		number = number / base;

	return (i);
}

/**
 * reverse_string - reverses a string
 * @str: string to reverse
 *
 * Return: reversed string
 */

char *reverse_string(char *str)
{
	char *rev;
	int i, j;
	int length = 0;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
	length++;
	}

	rev = malloc(sizeof(char) * (length + 1));
	if (rev == NULL)
	return (NULL);

	i = 0;
	for (j = (length - 1); j >= 0; j--)
	{
	rev[i] = str[j];
	i++;
	}

	return (rev);
}
