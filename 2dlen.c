#include "main.h"

/**
 * _str2dlen - Calculate the length of a 2D array of strings
 * @arr2d: The 2D array of strings to be measured.
 * Return: The number of strings in the 2D array
 */
int _str2dlen(char **arr2d)
{
	int len;

	len = 0;
	if (!arr2d)
		return (0);
	while (arr2d[len])
		len++;
	return (len);
}
