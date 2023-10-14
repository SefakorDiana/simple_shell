#include "main.h"
/**
 * _strlen - Calculate the length of a string.
 * @s: The string for which the length is to be calculated
 * Return: The length of the string
 */
size_t _strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}
