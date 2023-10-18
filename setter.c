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
	int space;
	list_t *circle;
	entry_t *start;

	space = _get_hash_code(key);
	circle = map->backets[space];
	while (circle)
	{
		start = circle->data;
		if (_strcmp(start->key, key))
		{
			free(start->value);
			start->value = _strdup(value);
			return (1);
		}
		circle = circle->next;
	}
	start = malloc(sizeof(entry_t));
	if (!start)
		return (0);
	start->key = _strdup(key);
	start->value = _strdup(value);
	add_to_list(&map->backets[space], start);
	return (1);
}
