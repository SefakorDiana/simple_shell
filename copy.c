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
	size_t iter;

	iter = 0;
	while (iter < size)
	{
		dest[iter] = src[iter];
		iter++;
	}
	dest[iter] = 0;
	return (dest);
}
