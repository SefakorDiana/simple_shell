#include "main.h"

/**
 * _realloc - Reallocate memory for a buffer with a new size.
 * @old_buffer: A pointer to the old buffer.
 * @old_size: The old size of the buffer
 * @new_size: The new size to which the buffer should be reallocated
 * Return:  A pointer to the reallocated buffer,
 * or NULL if memory allocation fails.
 */
void *_realloc(void *old_buffer, size_t old_size, size_t new_size)
{
	unsigned char *buffer;
	unsigned char *char_buffer;
	size_t iter;

	buffer = malloc(sizeof(unsigned char) * (new_size + 1));
	if (!buffer)
		return (NULL);
	char_buffer = old_buffer;
	iter = 0;
	while (char_buffer && iter < old_size)
	{
		buffer[iter] = char_buffer[iter];
		iter++;
	}

	while (iter < new_size)
	{
		buffer[iter] = 0;
		iter++;
	}
	buffer[iter] = 0;
	free(old_buffer);
	return (buffer);
}
