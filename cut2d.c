#include "main.h"

/**
 * _count_non_empty_string - Count the number of non-empty
 * strings in an array of strings.
 * @arr: The array of strings to be counted
 * Return:  The number of non-empty strings in the array
 */
int _count_non_empty_string(char **arr)
{
	int len;

	len = 0;
	while (*arr)
	{
		len += (**arr != '\0');
		arr++;
	}
	return (len);
}

/**
 * _trim_2darray - Remove empty strings from an array of strings.
 * @arr: The array of strings to be trimmed.
 * Return: The array of strings to be trimmed.
 */
char **_trim_2darray(char **arr)
{
	int len;
	char **new_arr;

	len = _count_non_empty_string(arr);
	new_arr = malloc(sizeof(char *) * (len + 1));
	if (!new_arr)
		return (NULL);
	new_arr[len] = NULL;
	len = 0;
	while (*arr)
	{
		if (**arr)
		{
			new_arr[len] = _strdup(*arr);
			len++;
		}
		arr++;
	}
	return (new_arr);
}
