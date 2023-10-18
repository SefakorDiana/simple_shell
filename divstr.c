#include "main.h"

/**
 * _strslice - Extract a substring from a given string.
 * @line: The original string from which the substring is extracted.
 * @start: The starting index of the substring
 * @end: The ending index of the substring.
 * Return: A pointer to the extracted substring
 */
char *_strslice(const char *line, int start, int end)
{
	char *strive;
	int measure, net;

	if (start < 0)
		start = 0;
	measure = _strlen(line);
	if (measure < end || end < 0)
		end = measure;
	strive = malloc(sizeof(char) * (end - start + 1));
	net = 0;
	while (start + net < end)
	{
		strive[net] = line[start + net];
		net++;
	}
	strive[net] = 0;
	return (strive);
}
