#include "main.h"

/**
 * add_to_list - New node to be added to end of list.
 * @lst: Pointer to pointer of head of list.
 * @data: Pointer to the data being stored.
 * Return: Pointer to the node newly added.
 */
list_t *add_to_list(list_t **lst, void *data)
{
	list_t *new_node = (list_t *)malloc(sizeof(list_t));
	list_t *current;

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->data = data;
	new_node->next = NULL;

	if (*lst == NULL)
	{
		*lst = new_node;
	}
	else
	{
		current = *lst;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}

	return (new_node);
}
