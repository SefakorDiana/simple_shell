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
	int numb;
	int sign;

	sign = 1;
	numb = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str)
	{
		numb = numb * 10 + (*str - 48);
		str++;
	}
	return (numb * sign);
}
