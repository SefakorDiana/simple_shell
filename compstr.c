#include "main.h"

/**
 * _strcmp - Compare two strings for equality
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 *
 * Return:  1 if the strings are equal,  0 if they are not
 */
int _strcmp(const char *str1, const char *str2)
{
	if (!str1 || !str2)
		return (0);
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (!*str1 && !*str2)
		return (1);
	return (0);
}
