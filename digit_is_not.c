#include "main.h"

/**
 * _isdigit - Check if a string represents a positive integer.
 * @s:a pointer to the string to be checked
 * Return: 1 if the string is a positive, 0 otherwise.
 */
int _isdigit(const char *s)
{
	if (!s)
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}
