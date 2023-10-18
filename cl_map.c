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
	int iterate;

	iterate = 0;
	while (iterate < BACKET_SIZE)
	{
		free_list(map->backets[iterate], _clear_entry);
		iterate++;
	}
	free(map);
}
