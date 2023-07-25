#include "hsh_main.h"

/**
 * _itoa - integer to ascii
 *
 * @value: value to be converted to a string
 * @base: numerical base used to represent the value as a string
 *
 * Return: a pointer to the resulting null-terminated string
 **/
char *_itoa(int value, int base)
{
	static char *array = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = value;

	if (value < 0)
	{
		n = -value;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *which contains a copy of the string given as a parameter
 *
 * @str: the string to copy
 *
 * Return: a pointer to character (sting copied)
 */
char *_strdup(char *str)
{
	int i, j;
	char *str_cpy = NULL;

	if (str == NULL)
		return (NULL);

	for (i = 0; *(str + i); i++)
		;

	str_cpy = (char *)malloc((sizeof(char) * i) + 1);

	if (str_cpy == NULL)
		return (NULL);

	for (j = 0; *(str + j); j++)
		*(str_cpy + j) = *(str + j);

	*(str_cpy + j) = '\0';

	return (str_cpy);
}
