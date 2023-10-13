#include "main.h"

/**
 * _clear_entry - frees the memory to be allocated
 * for an entry in the hash table.
 *
 * @data :  data to be entered
 *
 * Return: nothing
 */
void _clear_entry(void *data)
{
	entry_t *entry;

	entry = data;
	free(entry->key);
	free(entry->value);
	free(data);
}
