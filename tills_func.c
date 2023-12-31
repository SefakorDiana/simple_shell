#include "main.h"

/**
 *  _convert_env_into_2d_array - Convert environment variables into a 2D array.
 * Return: A 2D array containing environment variables
 * or NULL if memory allocation fails.
 */
char **_convert_env_into_2d_array(void)
{
	list_t *keys, *iterator;
	size_t len_iter;
	char **array;
	char *tmp[2];

	iterator = keys = _enviroment_management(GET_KEYS, NULL, NULL);
	len_iter = _listlen(keys);
	array = malloc(sizeof(char *) * (len_iter + 1));
	if (!array)
	{
		free_list(keys, free);
		return (NULL);
	}
	array[len_iter] = NULL;
	len_iter = 0;
	while (iterator)
	{
		tmp[0] = _strcat(iterator->data, "=");
		tmp[1] = _enviroment_management(GET_VALUE,
										iterator->data,
										NULL);
		array[len_iter] = _strcat(tmp[0], tmp[1]);
		free(tmp[0]);
		free(tmp[1]);
		iterator = iterator->next;
		len_iter++;
	}
	free_list(keys, free);
	return (array);
}

/**
 * _feed_enviroment_variable - Feed environment variables
 * into the shell's environment.
 * @new_env: An array of strings containing environment variable
 * Return: nothing
 */
void _feed_enviroment_variable(char **new_env)
{
	char **entry;

	while (*new_env)
	{
		entry = _split(*new_env, "=");
		_enviroment_management(SET_ENTRY, entry[0], entry[1]);
		_free_split(&entry);
		new_env++;
	}
}
