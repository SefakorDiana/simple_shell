#include "main.h"

/**
   * pop_from_list -  Remove and return the first node from a linked list.
   * @list: A pointer to a pointer to the head of the linked list.
   * Return:  A pointer to the data of the removed node
   * or NULL if the list is empty.
   */
void *pop_from_list(list_t **list)
{
	list_t *delete = *list;
	void *change = delete->data;

	if (!list && *list == NULL)
	{
		return (NULL);
	}

	*list = delete->next;
	free(delete);

	return (change);
}
