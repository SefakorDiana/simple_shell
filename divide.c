#include "main.h"

/**
 * check_diameter - Check if a string contains a specified diameter.
 * @str: The string to be checked for the specified diameter.
 * @diameter: The specified diameter to search for in the string
 * Return:  0 if not found, 1 if found but not at the end
 * 2 if found at the end.
 */
int check_diameter(const char *str, const char *diameter)
{
	size_t iter;

	iter = 0;
	while (str[iter] && diameter[iter] && str[iter] == diameter[iter])
		iter++;
	if (diameter[iter])
		return (0);
	if (str[iter] == diameter[iter - 1])
		return (2);
	return (1);
}

/**
 * backet_count - Count the occurrences of a specified diameter in a string.
 * @line: The string in which occurrences are counted.
 * @diameter: The specified diameter to count in the string.
 * Return: The count of specified diameter occurrences
 * considering trailing occurrences.
 */
size_t backet_count(const char *line, const char *diameter)
{
	size_t counter, index, before, is_diameter;

	counter = 0;
	index = 0;
	before = 0;
	if (!*line)
		return (0);
	while (line[index])
	{
		is_diameter = check_diameter(line + index, diameter);
		if (is_diameter)
		{
			if (is_diameter == 2)
			{
				index++;
				before = 1;
			}
			else if (is_diameter == 1 && before)
			{
				before = 0;
				index++;
			}
			else
			{
				counter++;
				index += _strlen(diameter);
			}
		}
		else
			index++;
	}
	return (counter + 1);
}

/**
 * get_next_diameter - Find the index of the next
 * occurrence of a specified diameter.
 * @line: The string in which to search for the next occurrence.
 * @diameter: The specified diameter to search for in the string.
 * Return: The index of the next occurrence of
 * the specified diameter in the string.
 */
size_t get_next_diameter(const char *line, const char *diameter)
{
	size_t index, before, is_diameter;

	index = 0;
	before = 0;
	while (line[index])
	{
		is_diameter = check_diameter(line + index, diameter);
		if (is_diameter)
		{
			if (is_diameter == 2)
			{
				index++;
				before = 1;
			}
			else if (is_diameter == 1 && before)
			{
				before = 0;
				index++;
			}
			else
				return (index);
		}
		else
			index++;
	}
	return (index);
}

/**
 * free_backets - Free memory allocated for an array of strings.
 * @backets:  An array of strings to be freed
 * @current_position: The number of strings in the array to be freed
 * Return: nothing
 */
void free_backets(char **backets, size_t current_position)
{
	size_t index;

	index = 0;
	while (index < current_position)
	{
		free(backets[index]);
		index++;
	}
	free(backets);
}
/**
 * _split -  Split a string into an array of substrings
 * using a specified diameter.
 * @line: The string to be split into substrings.
 * @diameter:  The specified diameter used for splitting the string.
 * Return:  An array of strings representing the substrings
 * or NULL if memory allocation fails.
 */
char **_split(const char *line, const char *diameter)
{
	char **backets;
	size_t backet_length, current_line_position, backet_index;
	size_t next_diameter;

	backet_length = backet_count(line, diameter);
	backets = malloc(sizeof(char *) * (backet_length + 1));
	if (!backets)
		return (NULL);
	current_line_position = 0;
	backet_index = 0;
	while (backet_index < backet_length)
	{
		next_diameter = get_next_diameter(line + current_line_position, diameter);
		backets[backet_index] = malloc(sizeof(char) * (next_diameter + 1));
		if (!backets[backet_index])
		{
			free_backets(backets, backet_index);
			return (NULL);
		}
		_copy(backets[backet_index], line + current_line_position, next_diameter);
		backet_index++;
		current_line_position += next_diameter + _strlen(diameter);
	}
	backets[backet_length] = NULL;
	return (backets);
}
