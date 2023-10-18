#include "main.h"
/**
 * _copy - Copies data into dest
 *
 * @dest: The buffer in which the data will be copied
 * @src: The buffer source of the char
 * @size: length of data to be copied into line
 * Return: dest
 */
char *_copy(char *dest, const char *src, size_t size)
{
	size_t iterator;

	iterator = 0;
	while (iterator < size)
	{
		dest[iterator] = src[iterator];
		iterator++;
	}
	dest[iterator] = 0;
	return (dest);
}
