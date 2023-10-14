#include "main.h"

/**
 * _check_invalid_characters_occurance -  Check for the occurrence of invalid
 * characters in a string.
 * @line:  A pointer to the string to be checked for invalid characters.
 * Return: 1 if the string contains any of the predefined invalid character
 *  0 otherwise.
 */
int _check_invalid_characters_occurance(char *line)
{
	size_t index, iter, iter2;
	char *invalid_characters[] = {
		";;",
		"|||",
		">>>",
		"<<"};

	index = 0;
	while (index < 4)
	{
		iter = 0;
		iter2 = 0;
		while (line[iter2] && invalid_characters[index][iter] &&
			   (invalid_characters[index][iter] == line[iter2] || line[iter2] == ' '))
		{
			if (line[iter2] == ' ')
				iter2++;
			else
			{
				iter2++;
				iter++;
			}
		}
		if (!invalid_characters[index][iter])
			return (1);
		index++;
	}
	return (0);
}

/**
 * _parsing_error_handler - Check for parsing errors in a string
 * @line: A pointer to the string to be checked for parsing errors.
 * Return:  0 if no parsing errors are found, 2 if parsing errors are detected.
 */
int _parsing_error_handler(char *line)
{
	size_t len;

	if (!line || !*line)
		return (0);
	len = _strlen(line);
	if (line[0] == ';' || line[0] == '|' ||
		line[len - 1] == '|' ||
		line[len - 1] == '>' || line[len - 1] == '<')
		return (2);
	len = 0;
	while (line[len])
	{
		if (_check_invalid_characters_occurance(line + len))
			return (2);
		len++;
	}
	return (0);
}
