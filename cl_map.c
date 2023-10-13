#include "main.h"

/**
 * _clear_map - frees the memory to be allocated
 * for an entry in the hash table.
 *
 *@map: freed map
 * Return: nothing
 */
void _clear_map(map_t *map)
{
	int iterator;

	iterator = 0;
	while (iterator < BACKET_SIZE)
	{
		free_list(map->backets[iterator], _clear_entry);
		iterator++;
	}
	free(map);
}
