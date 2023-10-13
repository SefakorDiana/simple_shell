#include "main.h"

/**
 * _atoi - A func to convert
 * string to an integer
 *
 * @str: being converted
 * Return: A converted integer
 */
int _atoi(const char *str)
{
	int number;
	int sign;

	sign = 1;
	number = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str)
	{
		number = number * 10 + (*str - 48);
		str++;
	}
	return (number * sign);
}
