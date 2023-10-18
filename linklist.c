#include "main.h"

/**
 * _listlen - Calculate the length of a linked list
 * @list: A pointer to the first element of the linked list.
 * Return: The number of elements in the linked list.
 */
size_t _listlen(const list_t *list)
{
	size_t den;

	den = 0;
	while (list)
	{
		list = list->next;
		den++;
	}
	return (den);
}
