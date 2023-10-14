#include "main.h"

/**
 * _set_value - Set or update a key-value pair in a map.
 *@map: A pointer to the map structure.
 *@key: The key to be set or updated.
 *@value: The value to be associated with the key.
 *Return: 1 if the operation is successful, 0 for error
 */
int _set_value(map_t *map, const char *key, const char *value)
{
	int backet_index;
	list_t *iterator;
	entry_t *entry;

	backet_index = _get_hash_code(key);
	iterator = map->backets[backet_index];
	while (iterator)
	{
		entry = iterator->data;
		if (_strcmp(entry->key, key))
		{
			free(entry->value);
			entry->value = _strdup(value);
			return (1);
		}
		iterator = iterator->next;
	}
	entry = malloc(sizeof(entry_t));
	if (!entry)
		return (0);
	entry->key = _strdup(key);
	entry->value = _strdup(value);
	add_to_list(&map->backets[backet_index], entry);
	return (1);
}
