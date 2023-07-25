#include "hsh_main.h"

/**
 * _strlen - returns the length of a string
 *
 * @s: the string whose length is to be found
 *
 * Return: the length of the given string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len])
	{
		len++;
	}

	return (len);
}

/**
 * _strcmp - compare twos strings
 *
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 *
 * Return: 0 if equal, signed difference between both otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
		i++;

	return (s1[i] - s2[i]);
}

/**
 * str_concat - concatenates two strings
 *
 * @s1: first string to concatenate
 * @s2: second string to concatenate
 *
 * Return: a pointer to character or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0, k = 0, l = 0;
	char *str_cat = NULL;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (s2 == NULL)
	{
		s2 = (char *)malloc(sizeof(char));
		s2[0] = '\0';
	}

	while (s1[i])
		i++;
	while (s2[j])
		j++;

	str_cat = (char *)malloc((sizeof(char) * (i + j)) + 1);

	if (str_cat == NULL)
		return (NULL);

	while (s1[k])
	{
		str_cat[k] = s1[k];
		k++;
	}

	while (s2[l])
	{
		str_cat[k] = s2[l];
		k++;
		l++;
	}

	str_cat[k] = '\0';
	return (str_cat);
}

/**
 * _puts - prints a string
 *
 * @str: pointer to the string to be printed
 *
 * Return: nothing
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i++]);
	}

	_putchar('\n');
}

/**
 * _putchar - writes the character c to stdout
 *
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
