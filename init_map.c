#include "main.h"

/**
 * _init_map - A func that initializes a new hash table
 * and returns a pointer to it.
 *
 * Return: a pointer to the inititialized map
 */
map_t *_init_map(void)
{
	map_t *map = (map_t *)malloc(sizeof(map_t));
	int    iterator;

	iterator = 0;
	while (iterator < BACKET_SIZE)
	{
		map->backets[iterator] = NULL;
		iterator++;
	}
	return (map);
}
