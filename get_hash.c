#include "main.h"

/**
 * _get_hash_code - A func that calculates the hash code
 * for a given key.
 *
 * @key: key to be hashed
 *
 * Return: return an integer which signifies hashed code
 * of the given key
 */
int _get_hash_code(const char *key)
{
	int hash = 0;
	int i;

	for (i = 0; key[i] != '\0'; i++)
	{
		hash += key[i];
	}

	return (hash % BACKET_SIZE);
}
