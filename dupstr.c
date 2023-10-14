#include "main.h"

/**
* _strdup - Duplicate a string in a newly allocated memory space
* @str:  The string to be duplicated.
* Return:  A pointer to the duplicated string
*/
char   *_strdup(const char *str)
{
	char *new_str;
	size_t  len, iterator;

	len = _strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	new_str[len] = 0;
	iterator = 0;
	while (iterator < len)
	{
		new_str[iterator] = str[iterator];
		iterator++;
	}
	return (new_str);
}
