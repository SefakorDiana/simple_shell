#include "main.h"

/**
 * _strcat  - Concatenate two strings and create a new string.
 * @str1: The first string to be concatenated
 * @str2: The second string to be concatenated.
 * Return:  A newly allocated string containing the
 * concatenated content of str1 and str2
 * or NULL if memory allocation fails.
 */
char *_strcat(const char *str1, const char *str2)
{
	size_t len1, len2, iter;
	char *newstr;

	len1 = _strlen(str1);
	len2 = _strlen(str2);
	newstr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!newstr)
		return (NULL);
	iter = 0;
	while (iter < len1)
	{
		newstr[iter] = str1[iter];
		iter++;
	}
	while (iter - len1 < len2)
	{
		newstr[iter] = str2[iter - len1];
		iter++;
	}
	newstr[iter] = 0;
	return (newstr);
}
